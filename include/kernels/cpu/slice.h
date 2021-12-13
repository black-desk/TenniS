#ifndef TENSORSTACK_KERNELS_CPU_SLICE_H
#define TENSORSTACK_KERNELS_CPU_SLICE_H

#include "backend/base/base_slice.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class Slice : public OperatorOnCPU<base::Slice> {
      public:
        using self   = Slice;
        using supper = OperatorOnCPU<base::Slice>;

        void slice(const Tensor &x, Tensor &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_SLICE_H
