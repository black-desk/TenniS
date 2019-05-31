#include <kernels/gpu/pooling2d.h>
#include <global/operator_factory.h>
#include <global/fp16_operator_factory.h>
#include <backend/name.h>

using namespace ts;
using namespace gpu;
TS_REGISTER_OPERATOR(Pooling2D, GPU, name::layer::pooling2d())
TS_REGISTER_FP16_OPERATOR(Pooling2D, GPU, name::layer::pooling2d())
