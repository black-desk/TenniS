#ifndef TENSORSTACK_KERNELS_CPU_GEMM_H
#define TENSORSTACK_KERNELS_CPU_GEMM_H

#include "backend/base/base_gemm.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class Gemm : public OperatorOnCPU<base::Gemm> {
      public:
        using self   = Gemm;
        using supper = OperatorOnCPU<base::Gemm>;

        void gemm(
          const Tensor &A,
          const Tensor &B,
          const Tensor &C,
          int           K,
          float         alpha,
          float         beta,
          bool          transA,
          bool          transB,
          Tensor       &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_GEMM_H
