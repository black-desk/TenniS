#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/depthwise_conv2d.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(DepthwiseConv2D, CPU, name::layer::depthwise_conv2d())
