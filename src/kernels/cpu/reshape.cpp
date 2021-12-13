#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/reshape.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(Reshape, CPU, name::layer::reshape())
