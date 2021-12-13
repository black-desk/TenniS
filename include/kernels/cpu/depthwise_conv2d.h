#ifndef TENSORSTACK_KERNELS_CPU_DEPTHWISE_CONV2D_H
#define TENSORSTACK_KERNELS_CPU_DEPTHWISE_CONV2D_H

#include "backend/base/base_depthwise_conv2d.h"
#include "depthwise_conv2d_core.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    using DepthwiseConv2D = base::PackedDepthwiseConv2DWithCore<
      OperatorOnCPU<base::DepthwiseConv2D>,
      DepthwiseConv2DCore>;
  }
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_DEPTHWISE_CONV2D_H