#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/transpose_conv2d.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(Conv2DTranspose, CPU, name::layer::transpose_conv2d())
