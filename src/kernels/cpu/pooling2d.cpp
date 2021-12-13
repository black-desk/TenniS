#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/pooling2d.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(Pooling2D, CPU, name::layer::pooling2d())
