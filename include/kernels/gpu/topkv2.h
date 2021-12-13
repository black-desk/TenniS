#ifndef TENSORSTACK_KERNELS_GPU_TOPKV2_H
#define TENSORSTACK_KERNELS_GPU_TOPKV2_H

#include "backend/base/base_topkv2.h"
#include "operator_on_gpu.h"

namespace ts
{
  namespace gpu
  {
    class Topkv2 : public OperatorOnGPU<base::Topkv2> {
      public:
        using self   = Topkv2;
        using supper = OperatorOnGPU<base::Topkv2>;

        void topkv2(
          const Tensor &x,
          int           K,
          bool          sorted,
          Tensor       &values,
          Tensor       &indices) override;
    };
  }  // namespace gpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_GPU_TOPKV2_H
