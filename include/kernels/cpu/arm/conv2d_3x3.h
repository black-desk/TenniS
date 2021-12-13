//
// Created by yang on 2019/10/11.
//

#ifndef TENSORSTACK_KERNELS_CPU_ARM_CONV2D_3X3_H
#define TENSORSTACK_KERNELS_CPU_ARM_CONV2D_3X3_H

#include "backend/common_structure.h"
#include "core/tensor.h"

namespace ts
{
  namespace cpu
  {
    namespace arm
    {
      template <typename T>
      class TS_DEBUG_API Conv2d3x3 {
        public:
          static void conv2d_3x3_s1(
            const Tensor    &x,
            const Padding2D &padding,
            float            padding_value,
            const Tensor    &w,
            Tensor          &out);

          static void conv2d_3x3_s2(
            const Tensor    &x,
            const Padding2D &padding,
            float            padding_value,
            const Tensor    &w,
            Tensor          &out);
      };
    }  // namespace arm
  }    // namespace cpu
}  // namespace ts

#endif  // TENSORSTACK_KERNELS_CPU_ARM_CONV2D_3X3_H
