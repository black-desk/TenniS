//
// Created by kier on 2019/9/5.
//

#ifndef TENSORSTACK_THIRD_DRAGON_H
#define TENSORSTACK_THIRD_DRAGON_H

#include <frontend/intime.h>
#include <runtime/operator.h>

#include <numeric>
#include <set>

#include "core/tensor.h"
#include "core/tensor_builder.h"
#include "dragon/context_cpu.h"
#include "dragon/context_cuda.h"
#include "dragon/logging.h"
#include "dragon/op_kernel.h"
#include "dragon/operator.h"
#include "dragon/tensor.h"
#include "dragon/type_meta.h"
#include "dragon/workspace.h"

namespace ts
{
  namespace dragon
  {
    using std::string;
    using std::vector;
  }  // namespace dragon
}  // namespace ts

#endif  // TENSORSTACK_THIRD_DRAGON_H
