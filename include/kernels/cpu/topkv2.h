#ifndef TENSORSTACK_KERNELS_CPU_TOPKV2_H
#define TENSORSTACK_KERNELS_CPU_TOPKV2_H

#include "backend/base/base_topkv2.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class Topkv2 : public OperatorOnCPU<base::Topkv2> {
      public:
        using self   = Topkv2;
        using supper = OperatorOnCPU<base::Topkv2>;

        void topkv2(
          const Tensor &x,
          int           K,
          bool          sorted,
          Tensor       &values,
          Tensor       &indices) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_TOPKV2_H
