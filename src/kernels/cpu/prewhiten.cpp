#include <kernels/cpu/prewhiten.h>
#include <algorithm>

#include "backend/name.h"

namespace ts {

	void PreWhiten::init()
	{
		supper::init();
	}

	int PreWhiten::run(ts::Stack &stack)
	{
		std::vector<ts::Tensor::Prototype> output;

		this->infer(stack, output);
		stack.push(output[0], memory_device());

		auto dtype = stack.index(0)->dtype();
		switch (dtype) {
#define DECLARE_TYPE_AND_RUN(DTYPE, TYPE) \
				case DTYPE: { pre_whiten<TYPE>(stack); break; }
				DECLARE_TYPE_AND_RUN(INT8, int8_t);
				DECLARE_TYPE_AND_RUN(UINT8, uint8_t);
				DECLARE_TYPE_AND_RUN(INT16, int16_t);
				DECLARE_TYPE_AND_RUN(UINT16, uint16_t);
				DECLARE_TYPE_AND_RUN(INT32, int32_t);
				DECLARE_TYPE_AND_RUN(UINT32, uint32_t);
				DECLARE_TYPE_AND_RUN(INT64, int64_t);
				DECLARE_TYPE_AND_RUN(UINT64, uint64_t);
				DECLARE_TYPE_AND_RUN(FLOAT32, float);
				DECLARE_TYPE_AND_RUN(FLOAT64, double);
	#undef DECLARE_TYPE_AND_RUN
			default: {
				TS_LOG_ERROR << "pre_whiten not support this data type: " << dtype << eject;
				break;
			}
		}
		return 1;
	}

	int PreWhiten::infer(ts::Stack &stack, std::vector<ts::Tensor::Prototype> &output)
	{
		int input_num = stack.size();
		TS_AUTO_CHECK(input_num == 1);

		TS_AUTO_CHECK(stack.index(0)->dtype() == FLOAT32 || stack.index(0)->dtype() == FLOAT64);

		output.resize(1);
		output[0] = ts::Tensor::Prototype(stack.index(0)->dtype(), stack.index(0)->sizes());

		return 1;
	}

	template<typename T>
	bool PreWhiten::pre_whiten(ts::Stack &stack)
	{
		ts::Tensor& output_tensor = *stack.index(-1);
		auto output_shape = output_tensor.sizes();
		auto input_memory = stack.index(0)->sync(memory_device());
		auto device_type = input_memory.device();
		T* input_data = input_memory.data<T>();
		T* output_data = output_tensor.data<T>();
		int count = output_tensor.count();
		memcpy(output_data, device_type, count * sizeof(T), input_data, device_type, count * sizeof(T));

		double mean = 0;
		double std_dev = 0;
		T *at = nullptr;

		at = output_data;
		for (size_t i = 0; i < count; ++i, ++at) mean += *at;
		mean /= count;

		at = output_data;
		for (size_t i = 0; i < count; ++i, ++at) std_dev += (*at - mean) * (*at - mean);
		std_dev = std::sqrt(std_dev / count);
		std_dev = std::max<T>(std_dev, 1 / std::sqrt(count));
		double std_dev_rec = 1 / std_dev;

		at = output_data;
		for (size_t i = 0; i < count; ++i, ++at) {
			*at -= mean;
			*at *= std_dev_rec;
		}

		return true;
	}
}

using namespace ts;
TS_REGISTER_OPERATOR(PreWhiten, ts::CPU, "prewhiten")
