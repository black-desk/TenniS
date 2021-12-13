#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/shape.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(GetShape, CPU, name::layer::shape())
