#ifndef TENSORSTACK_GLOBAL_CUBLAS_DEVICE_H
#define TENSORSTACK_GLOBAL_CUBLAS_DEVICE_H

#include <cublas_v2.h>
#include <cuda_runtime.h>

#include "core/device.h"
#include "global/device_admin.h"
#include "utils/log.h"

namespace ts
{

  class CUDAContextHandle {
    public:
      using self = CUDAContextHandle;

      CUDAContextHandle(int id) {
        auto cuda_error = cudaSetDevice(id);
        if (cuda_error != cudaSuccess) {
          TS_LOG_ERROR << "cudaSetDevice(" << id << ") failed. Error("
                       << cuda_error << "): " << cudaGetErrorString(cuda_error)
                       << eject;
        }
        if (cublasCreate(&m_cublas_handle) != CUBLAS_STATUS_SUCCESS)
          TS_LOG_ERROR << "The cublasHandle_t initialize failed " << eject;

        int flags = cudaStreamNonBlocking;  // cudaStreamDefault
        if (cudaStreamCreateWithFlags(&m_stream, flags) != cudaSuccess) {
          TS_LOG_ERROR << "The cudaStream_t initialize failed " << eject;
        }
        // TODO: use stream run kernel and cublas function
        cublasSetStream(m_cublas_handle, m_stream);
      }

      ~CUDAContextHandle() {
        cublasDestroy(m_cublas_handle);
        cudaStreamDestroy(m_stream);
      }

      cublasHandle_t cublas_handle() { return m_cublas_handle; }
      cudaStream_t   stream() { return m_stream; }
    private:
      cublasHandle_t m_cublas_handle;
      cudaStream_t   m_stream;
  };

  void DeviceCuBLASAdminFunction(
    DeviceHandle **handle, int device_id, DeviceAdmin::Action action);
}  // namespace ts

#endif  // TENSORSTACK_GLOBAL_CUBLAS_DEVICE_H