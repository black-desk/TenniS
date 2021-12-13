#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/cast.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(CastV2, CPU, name::layer::cast())
