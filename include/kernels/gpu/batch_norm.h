#ifndef TENSORSTACK_KERNELS_GPU_BATCH_NORM_H
#define TENSORSTACK_KERNELS_GPU_BATCH_NORM_H

#include "backend/base/base_batch_norm.h"
#include "operator_on_gpu.h"

namespace ts
{
  namespace gpu
  {
    class BatchNorm : public OperatorOnGPU<base::BatchNorm> {
      public:
        using self   = BatchNorm;
        using supper = OperatorOnGPU<base::BatchNorm>;

        BatchNorm() = default;

        void batch_norm(
          const Tensor &x,
          const Tensor &mean,
          const Tensor &variance,
          int           dim,
          float         epsilon,
          Tensor       &out) override;
    };
  }  // namespace gpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_GPU_BATCH_NORM_H
