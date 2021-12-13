#ifndef TENSORSTACK_KERNELS_GPU_DIV_H
#define TENSORSTACK_KERNELS_GPU_DIV_H

#include <backend/base/base_div.h>
#include <core/tensor.h>
#include <runtime/stack.h>

#include "operator_on_gpu.h"

namespace ts
{
  namespace gpu
  {
    class Div : public OperatorOnGPU<base::Div> {
      public:
        using self   = Div;
        using supper = OperatorOnGPU<base::Div>;

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
  }  // namespace gpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_GPU_DIV_H
