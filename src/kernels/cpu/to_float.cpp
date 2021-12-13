#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/to_float.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(ToFloat, CPU, name::layer::to_float())
