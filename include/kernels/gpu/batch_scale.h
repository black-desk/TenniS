#ifndef TENSORSTACK_KERNELS_GPU_BATCH_SCALE_H
#define TENSORSTACK_KERNELS_GPU_BATCH_SCALE_H

#include "backend/base/base_batch_scale.h"
#include "operator_on_gpu.h"

namespace ts
{
  namespace gpu
  {
    class BatchScale : public OperatorOnGPU<base::BatchScale> {
      public:
        using self   = BatchScale;
        using supper = OperatorOnGPU<base::BatchScale>;

        BatchScale() = default;

        void batch_scale(
          const Tensor &x,
          const Tensor &scale,
          const Tensor &bias,
          int           dim,
          Tensor       &out) override;
    };
  }  // namespace gpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_GPU_BATCH_SCALE_H
