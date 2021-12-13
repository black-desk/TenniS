#ifndef TENSORSTACK_KERNELS_CPU_RESHAPE_H
#define TENSORSTACK_KERNELS_CPU_RESHAPE_H

#include "backend/base/base_reshape.h"

namespace ts
{
  namespace cpu
  {
    using Reshape = OperatorOnAny<base::Reshape>;
  }
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_RESHAPE_H