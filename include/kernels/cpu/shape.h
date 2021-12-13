#ifndef TENSORSTACK_KERNELS_CPU_SHAPE_H
#define TENSORSTACK_KERNELS_CPU_SHAPE_H

#include "backend/base/base_shape.h"

namespace ts
{
  namespace cpu
  {
    using GetShape = OperatorOnAny<base::GetShape>;
  }
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_SHAPE_H