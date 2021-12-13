#ifndef TENSORSTACK_KERNELS_CPU_CONV2DTranspose_H
#define TENSORSTACK_KERNELS_CPU_CONV2DTranspose_H

#include "backend/base/base_conv2d_transpose.h"
#include "operator_on_cpu.h"
#include "transpose_conv2d_core.h"

namespace ts
{
  namespace cpu
  {
    using Conv2DTranspose = base::PackedConv2DTransposeWithCore<
      OperatorOnCPU<base::Conv2DTranspose>,
      Conv2DTransposeCore>;
  }
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_CONV2D_H
