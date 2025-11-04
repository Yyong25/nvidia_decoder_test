/*
 * Test Demo for cuvidGetDecoderCaps
 * 测试 NVIDIA Video Codec SDK 解码器能力查询功能
 */

 #include <iostream>
 #include <cstring>
 #include <functional>
 #include <cuda.h>
 #include "cuviddec.h"
 #include "nvcuvid.h"
 
 int main(int argc, char* argv[]) {
     CUcontext cuContext = nullptr;
     int deviceCount = 0;
     cuDeviceGetCount(&deviceCount);
     cuInit(0);
     CUdevice cuDevice;
     cuDeviceGet(&cuDevice, 0);
     cuCtxCreate(&cuContext,CU_CTX_SCHED_AUTO, cuDevice);
 
     // 测试1: H.264 8-bit 420
     CUVIDDECODECAPS decodecaps;
     memset(&decodecaps, 0, sizeof(decodecaps));
     decodecaps.eCodecType = cudaVideoCodec_H264;
     decodecaps.eChromaFormat = cudaVideoChromaFormat_420;
     decodecaps.nBitDepthMinus8 = 0;
     
     cuCtxPushCurrent(cuContext);
     auto result = cuvidGetDecoderCaps(&decodecaps);
     if(result != CUDA_SUCCESS) {
         printf("cuvidGetDecoderCaps fail code error %d \n", result);
         return -1;
     }
     else
     {
        printf("cuvidGetDecoderCaps成功\n");
        printf("bIsSupported: %d\n", decodecaps.bIsSupported);
        printf("nNumNVDECs: %d\n", decodecaps.nNumNVDECs);
        printf("nOutputFormatMask: %d\n", decodecaps.nOutputFormatMask);
        printf("nMaxWidth: %d\n", decodecaps.nMaxWidth);
        printf("nMaxHeight: %d\n", decodecaps.nMaxHeight);
        printf("nMaxMBCount: %d\n", decodecaps.nMaxMBCount);
        printf("nMinWidth: %d\n", decodecaps.nMinWidth);
        printf("nMinHeight: %d\n", decodecaps.nMinHeight);
     }
     cuCtxDestroy(cuContext);
     return 0;
 }
 

 