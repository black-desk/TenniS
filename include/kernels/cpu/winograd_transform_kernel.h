#ifndef TENSORSTACK_KERNELS_CPU_WINOGRAD_TRANSFORM_KERNEL_H
#define TENSORSTACK_KERNELS_CPU_WINOGRAD_TRANSFORM_KERNEL_H

#include "backend/base/base_winograd_transform_kernel.h"
#include "operator_on_cpu.h"

namespace ts
{
  namespace cpu
  {
    class WinogradTransKernel :
      public OperatorOnCPU<base::WinogradTransKernel> {
      public:
        using self   = WinogradTransKernel;
        using supper = OperatorOnCPU<base::WinogradTransKernel>;

        void transform_kernel(
          const Tensor &x, WinogradConv2DMode winograd_mode, Tensor &out);
    };
  }  // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_WINOGRAD_TRANSFORM_KERNEL_H