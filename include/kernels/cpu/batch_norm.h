#ifndef TENSORSTACK_KERNELS_CPU_BATCH_NORM_H
#define TENSORSTACK_KERNELS_CPU_BATCH_NORM_H

#include "backend/base/base_batch_norm.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class BatchNorm : public OperatorOnCPU<base::BatchNorm> {
      public:
        using self   = BatchNorm;
        using supper = OperatorOnCPU<base::BatchNorm>;

        BatchNorm() = default;

        void batch_norm(
          const Tensor &x,
          const Tensor &mean,
          const Tensor &variance,
          int           dim,
          float         epsilon,
          Tensor       &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_BATCH_NORM_H
