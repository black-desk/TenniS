#include <backend/name.h>
#include <global/operator_factory.h>
#include <kernels/cpu/unsqueeze.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(Unsqueeze, CPU, name::layer::unsqueeze())
