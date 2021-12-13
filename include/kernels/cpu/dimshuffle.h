#ifndef TENSORSTACK_KERNELS_CPU_DIMSHUFFLE_H
#define TENSORSTACK_KERNELS_CPU_DIMSHUFFLE_H

#include "backend/base/base_dimshuffle.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class Dimshuffle : public OperatorOnAny<base::Dimshuffle> {
      public:
        using self   = Dimshuffle;
        using supper = OperatorOnAny<base::Dimshuffle>;

        Dimshuffle() = default;

        void dimshuffle(
          const Tensor           &x,
          int                     dim,
          const std::vector<int> &shuffle,
          Tensor                 &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_DIMSHUFFLE_H