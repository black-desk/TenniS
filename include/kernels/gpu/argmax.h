#ifndef TENSORSTACK_KERNELS_GPU_ARGMAX_H
#define TENSORSTACK_KERNELS_GPU_ARGMAX_H

#include "backend/base/base_argmax.h"
#include "operator_on_gpu.h"

namespace ts
{
  namespace gpu
  {
    class ArgMax : public OperatorOnGPU<base::ArgMax> {
      public:
        using self   = ArgMax;
        using supper = OperatorOnGPU<base::ArgMax>;

        void argmax(const Tensor &x, int dim, Tensor &out) override;
    };
  }  // namespace gpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_GPU_ARGMAX_H
