#ifndef TENSORSTACK_KERNELS_CPU_STACK_TENSOR_H
#define TENSORSTACK_KERNELS_CPU_STACK_TENSOR_H

#include "backend/base/base_stack_tensor.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class StackTensor : public OperatorOnAny<base::StackTensor> {
      public:
        using self   = StackTensor;
        using supper = OperatorOnAny<base::StackTensor>;

        StackTensor() = default;

        void init() override;

        int run(Stack &stack) override;

        void stack_tensor(
          const std::vector<Tensor> &x, int axis, Tensor &out) override;
      private:
        Operator::shared m_op_concat;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_STACK_TENSOR_H