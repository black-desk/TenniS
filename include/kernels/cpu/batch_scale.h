#ifndef TENSORSTACK_KERNELS_CPU_BATCH_SCALE_H
#define TENSORSTACK_KERNELS_CPU_BATCH_SCALE_H

#include "backend/base/base_batch_scale.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class BatchScale : public OperatorOnCPU<base::BatchScale> {
      public:
        using self   = BatchScale;
        using supper = OperatorOnCPU<base::BatchScale>;

        BatchScale() = default;

        void batch_scale(
          const Tensor &x,
          const Tensor &scale,
          const Tensor &bias,
          int           dim,
          Tensor       &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_BATCH_SCALE_H
