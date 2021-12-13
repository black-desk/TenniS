#ifndef TENSORSTACK_KERNELS_GPU_ADD_BIAS_H
#define TENSORSTACK_KERNELS_GPU_ADD_BIAS_H

#include <backend/base/base_add_bias.h>
#include <core/tensor.h>
#include <runtime/operator.h>
#include <runtime/stack.h>

#include "operator_on_gpu.h"

namespace ts
{
  namespace gpu
  {
    class AddBias : public OperatorOnGPU<base::AddBias> {
      public:
        using self   = AddBias;
        using supper = OperatorOnGPU<base::AddBias>;

        AddBias() = default;

        void add(
          const Tensor &x, const Tensor &b, int dim, Tensor &out) override;
    };
  }  // namespace gpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_GPU_ADD_BIAS_H
