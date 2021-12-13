#ifndef TENSORSTACK_KERNELS_CPU_DIV_H
#define TENSORSTACK_KERNELS_CPU_DIV_H

#include <backend/base/base_div.h>
#include <core/tensor.h>
#include <runtime/stack.h>

#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class Div : public OperatorOnCPU<base::Div> {
      public:
        using self   = Div;
        using supper = OperatorOnCPU<base::Div>;

        void reduce_with_broadcast(
          const Tensor &lhs, const Tensor &rhs, Tensor &out) override;

        void reduce_with_same_shape(
          const Tensor &lhs, const Tensor &rhs, Tensor &out) override;

        void reduce_with_bias(
          const Tensor &lhs, const Tensor &rhs, Tensor &out, int dim) override;

        void reduce_with_scalar(
          const Tensor &lhs, const Tensor &rhs, Tensor &out) override;

        void reduce_with_bias_cross(
          const Tensor &lhs, const Tensor &rhs, Tensor &out, int dim) override;

        void reduce_with_scalar_cross(
          const Tensor &lhs, const Tensor &rhs, Tensor &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_DIV_H
