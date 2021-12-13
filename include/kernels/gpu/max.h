#ifndef TENSORSTACK_KERNELS_GPU_MAX_H
#define TENSORSTACK_KERNELS_GPU_MAX_H

#include "backend/base/base_max.h"
#include "operator_on_gpu.h"

namespace ts
{
  namespace gpu
  {
    class Max : public OperatorOnGPU<base::Max> {
      public:
        using self   = Max;
        using supper = OperatorOnGPU<base::Max>;

        void max(const Tensor &x, Tensor &out) override;
    };
  }  // namespace gpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_GPU_MAX_H
