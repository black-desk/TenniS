//
// Created by kier on 2019/3/6.
//

#ifndef TENSORSTACK_KERNELS_CPU_GATHER_H
#define TENSORSTACK_KERNELS_CPU_GATHER_H

#include "backend/base/base_gather.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class Gather : public OperatorOnAny<base::Gather> {
      public:
        using self   = Gather;
        using supper = OperatorOnCPU<base::Gather>;

        void gather(
          const Tensor &x,
          const Tensor &indices,
          int           axis,
          Tensor       &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_GATHER_H
