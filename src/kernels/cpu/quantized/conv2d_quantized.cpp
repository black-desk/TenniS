#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/quantized/conv2d_quantized.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(Conv2DQuantized, CPU, name::layer::conv2d_quantized())
