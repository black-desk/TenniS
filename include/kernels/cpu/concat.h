#ifndef TENSORSTACK_KERNELS_CPU_CONCAT_H
#define TENSORSTACK_KERNELS_CPU_CONCAT_H

#include "backend/base/base_concat.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class Concat : public OperatorOnAny<base::Concat> {
      public:
        using self   = Concat;
        using supper = OperatorOnAny<base::Concat>;

        Concat() = default;

        void concat(
          const std::vector<Tensor> &x, int dim, Tensor &out) override;
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_CONCAT_H