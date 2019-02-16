#include <kernels/cpu/conv2d.h>
#include <core/tensor_builder.h>
#include <kernels/cpu/math_cpu.h>
#include <kernels/cpu/im2col.h>
#include <global/operator_factory.h>
#include <backend/name.h>
#include <core/device.h>
#include <utils/assert.h>
#ifdef TS_USE_CBLAS
#include <kernels/cblas/math_cblas.h>
#endif

namespace ts {
    namespace cpu {

        template<typename T>
        static void cpu_conv2d_nchw_compute_run(const Tensor &x, const Padding2D &padding, float padding_value,
                                           const Tensor &w, const Stride2D &stride, const Dialations2D &dialations,
                                           Tensor &out, Stack &stack) {
            auto weight_shape = w.sizes();
            auto reshape = out.sizes();
            auto shape = x.sizes();
            int kernel_dims = weight_shape[1] * weight_shape[2] * weight_shape[3];
            int conv_out_spatial_dim = reshape[2] * reshape[3];
            //int col_offset = kernel_dims * conv_out_spatial_dim;
            //int weight_offset = weight_shape[0] * kernel_dims;
            int output_number_offset = reshape[1] * conv_out_spatial_dim;
            int input_number_offset = shape[1] * shape[2] * shape[3];
            int col_buffer_size = shape[1] * weight_shape[2] * weight_shape[3] * reshape[2] * reshape[3];

            const T *pinput = x.data<T>();
            const T *pweight = w.data<T>();
            T *poutput = out.data<T>();

            Tensor col_tensor;
            T *col_buffer = nullptr;

            bool is_1x1_conv = stride.height == 1 && stride.width == 1 &&
                               weight_shape[2] == 1 && weight_shape[3] == 1 &&
                               padding.top == 0 && padding.bottom == 0 &&
                               padding.left == 0 && padding.right == 0;

            // 1x1 conv do not need im2col
            if (!is_1x1_conv) {
                Shape col_shape;
                col_shape.resize(1);
                col_shape[0] = col_buffer_size;
                col_tensor = stack.make(out.dtype(), col_shape, MemoryDevice(CPU));
                col_buffer = col_tensor.data<T>();
            }

            for (int i = 0; i < shape[0]; i++) {
                if (is_1x1_conv) {
                    //std::memcpy(col_buffer,pinput,sizeof(T)*col_buffer_size);
                    col_buffer = const_cast<T *>(pinput);
                } else {
                    ::memset(col_buffer, 0, col_buffer_size * sizeof(T));
                    im2col_cpu(pinput, shape[1], shape[2], shape[3], weight_shape[2], weight_shape[3],
                               padding.top, padding.bottom,
                               padding.left, padding.right,
                               stride.height, stride.width,
                               dialations.height, dialations.width,
                               col_buffer, T(padding_value));
                }
#ifdef TS_USE_CBLAS
                cblas::math<T>::gemm(ts::blas::NoTrans, ts::blas::NoTrans, weight_shape[0], conv_out_spatial_dim,
                                     kernel_dims, 1.0, pweight, col_buffer, 0, poutput);
#else
                cpu::math<T>::gemm(ts::blas::NoTrans,ts::blas::NoTrans, weight_shape[0], conv_out_spatial_dim,
                               kernel_dims, 1.0, pweight, col_buffer, 0, poutput);
#endif
                pinput += input_number_offset;
                poutput += output_number_offset;
            }
        }

        void Conv2D::conv2d(const Tensor &x, const Padding2D &padding, float padding_value, const Tensor &w,
                            const Stride2D &stride, const Dialations2D &dialations, Conv2DFormat format, Tensor &out,
                            Stack &stack) {
            if (format != FORMAT_NCHW) {
                TS_LOG_ERROR << op() << " do not support format:" << tensor::to_string(get(name::format)) << eject;
            }
            DTYPE dtype = out.dtype();
            switch (dtype) {
#define DECLARE_COMPUTE_RUN(DTYPE, TYPE) \
        case DTYPE: { cpu_conv2d_nchw_compute_run<TYPE>(x, padding, padding_value, w, stride, dialations, out, stack);; break; }
                DECLARE_COMPUTE_RUN(FLOAT32, float);
                DECLARE_COMPUTE_RUN(FLOAT64, double);
#undef DECLARE_COMPUTE_RUN
                default: {
                    TS_LOG_ERROR << this->op() << " not support this data type: " << dtype << eject;
                    break;
                }
            }
        }
    }
}
using namespace ts;
using namespace cpu;
TS_REGISTER_OPERATOR(Conv2D, CPU, name::layer::conv2d())
