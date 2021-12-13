#ifndef TENSORSTACK_KERNELS_CPU_ARGMAX_H
#define TENSORSTACK_KERNELS_CPU_ARGMAX_H

#include "backend/base/base_argmax.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class ArgMax : public OperatorOnCPU<base::ArgMax> {
      public:
        using self   = ArgMax;
        using supper = OperatorOnCPU<base::ArgMax>;

        void argmax(const Tensor &x, int dim, Tensor &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_ARGMAX_H
