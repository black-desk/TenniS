#include <backend/name.h>
#include <core/tensor_builder.h>
#include <global/operator_factory.h>
#include <kernels/cpu/flatten.h>

using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(Flatten, CPU, name::layer::flatten())
