//
// Created by kier on 19-6-17.
//

#include "global/operator_factory.h"
#include "runtime/operator.h"
#include "runtime/stack.h"

namespace ts
{
  namespace cpu
  {
    class Dims : public Operator {
        int run(Stack &stack) final {
          TS_AUTO_CHECK(stack.size() == 1);
          auto &dims = *stack.push(INT32, Shape(), MemoryDevice(CPU));
          dims.data<int32_t>(0) = int(stack [0].dims());
          return 1;
        }

        int infer(Stack &stack, std::vector<Tensor::Prototype> &output) final {
          output.resize(1);
          output [0] = Tensor::Prototype(INT32, Shape());
          return 1;
        }
    };
  }  // namespace cpu
}  // namespace ts

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(Dims, CPU, "_dims")