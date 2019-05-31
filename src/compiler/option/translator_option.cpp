#include "compiler/option/translator_option.h"

#include "backend/name.h"
#include "core/tensor_builder.h"
#include "module/menu.h"

#include "global/fp16_operator_factory.h"

namespace ts {

    static std::vector<const TranslatorOption*> &GetStaticTranslateOptions() {
        static std::vector<const TranslatorOption*> options;
        return options;
    }

    const std::vector<const TranslatorOption*> &GetFullTranslateOptions() {
        return GetStaticTranslateOptions();
    }

    void RegisterTranslateOption(const TranslatorOption *option) {
        auto &options = GetStaticTranslateOptions();
        options.emplace_back(option);
    }

    class Fp16TranslatorOption : public TranslatorOption {
    public:
        bool translate(const ComputingDevice &device,
            const Node node,
            Node &translated_node,
            bool output_flag ) const final {

            if (device.type() != GPU)
                return false;

            auto op_name = node.bubble().op();

            if (Bubble::IsEndPoint(op_name)) {
                if (op_name == Bubble::Parameter)
                    translated_node = bubble::param(node.bubble().name());
                else if(op_name == Bubble::Const)
                    translated_node = bubble::bubble(node.bubble());
                return true;
            }         

            if (op_name == name::layer::cast()) {
                translated_node = bubble::bubble(node.bubble());
                Node::Link(translated_node, node.inputs());
                return true;
            }

            if (op_name == name::layer::to_float()) {
                translated_node = bubble::bubble(node.bubble());
                Node::Link(translated_node, node.inputs());
                return true;
            }
               
            auto fp16_op_creator = Fp16OperatorCreator::Query(device.type(), node.bubble().op(), false);

            //status 0: current node is output but stream is fp16
            if (output_flag && fp16_op_creator != nullptr) {
                auto cast_fp32_node = bubble::op(node.bubble().name() + "_cast_fp32", name::layer::cast(), { node });
                Tensor dtype = tensor::from<int>(DTYPE::FLOAT32);
                cast_fp32_node.bubble().set(name::dtype, dtype);
                translated_node = cast_fp32_node;
                return true;
            }

            std::vector<Node> translated_inputs;
            bool const_to_fp16 = true;
            
            auto inputs = node.inputs();
            for (auto input : inputs) {
                //check current stream is fp16 or fp32 
                auto input_creator = Fp16OperatorCreator::Query(device.type(), input.bubble().op(), false);
                bool stream_is_fp16 = false;
                if (input.bubble().op() == name::layer::cast()) {
                    auto dtype = tensor::to_int(input.bubble().get(name::dtype));
                    stream_is_fp16 = (dtype == FLOAT16) && input_creator != nullptr;
                }
                else if (Bubble::IsEndPoint(input.bubble().op())) {
                    if (input.bubble().op() == Bubble::Const) {
                        auto dtype = input.bubble().get(name::value).dtype();
                        //only fp16,fp32,fp64 can convert to fp16
                        if (dtype != FLOAT16 && dtype != FLOAT32 && dtype != FLOAT64) {
                            const_to_fp16 = false;
                        }
                        stream_is_fp16 = (dtype == FLOAT16);
                    }
                }
                else {
                    stream_is_fp16 = input_creator != nullptr;
                }

                //status: current stream is not fp16 but op support fp16 and to_fp16 is true
                if (!stream_is_fp16 && fp16_op_creator != nullptr && const_to_fp16) {
                    auto cast_fp16_node = bubble::op(input.bubble().name() + "_cast_fp16", name::layer::cast(), { input });
                    Tensor dtype = tensor::from<int>(DTYPE::FLOAT16);
                    cast_fp16_node.bubble().set(name::dtype, dtype);
                    translated_inputs.emplace_back(cast_fp16_node);
                }
                else if (stream_is_fp16 && fp16_op_creator == nullptr) {
                    auto cast_fp32_node = bubble::op(input.bubble().name() + "_cast_fp32", name::layer::cast(), { input });
                    Tensor dtype = tensor::from<int>(DTYPE::FLOAT32);
                    cast_fp32_node.bubble().set(name::dtype, dtype);
                    translated_inputs.emplace_back(cast_fp32_node);
                }
                else {
                    translated_inputs.emplace_back(input);
                }
            }

            translated_node = bubble::bubble(node.bubble());
            Node::Link(translated_node, translated_inputs);
            return true;

        }
    };
}

TS_REGISTER_TRANSLATOR_OPTION(ts::Fp16TranslatorOption);
