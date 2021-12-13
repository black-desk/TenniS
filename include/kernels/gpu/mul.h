#ifndef TENSORSTACK_KERNELS_GPU_MUL_H
#define TENSORSTACK_KERNELS_GPU_MUL_H

#include <backend/base/base_mul.h>
#include <core/tensor.h>
#include <runtime/stack.h>

#include "operator_on_gpu.h"

namespace ts
{
  namespace gpu
  {
    class Mul : public OperatorOnGPU<base::Mul> {
      public:
        using self   = Mul;
        using supper = OperatorOnGPU<base::Mul>;

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

#endif  // TENSORSTACK_KERNELS_GPU_MUL_H
