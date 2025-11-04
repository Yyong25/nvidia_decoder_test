cmake_minimum_required(VERSION 3.10)
project(TestDecoderCaps)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(test_decoder_caps test_decoder_caps.cpp)

# 查找CUDA
find_package(CUDA REQUIRED)

# 设置CUDA包含目录
include_directories(${CUDA_INCLUDE_DIRS})


# 查找CUDA库
find_library(CUDA_LIB cuda 
    PATHS 
        ${CUDA_TOOLKIT_ROOT_DIR}/lib64
        ${CUDA_TOOLKIT_ROOT_DIR}/lib
    REQUIRED
)

find_library(NVCUVID_LIB nvcuvid
    PATHS
        ${CUDA_TOOLKIT_ROOT_DIR}/lib64
        ${CUDA_TOOLKIT_ROOT_DIR}/lib
    REQUIRED
)

# 链接库
target_link_libraries(test_decoder_caps
    ${CUDA_LIB}
    ${NVCUVID_LIB}
    dl
    pthread
)

# 设置编译选项
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(test_decoder_caps PRIVATE -Wall -Wextra)
endif()

# 输出信息
message(STATUS "CUDA_INCLUDE_DIRS: ${CUDA_INCLUDE_DIRS}")
message(STATUS "CUDA_TOOLKIT_ROOT_DIR: ${CUDA_TOOLKIT_ROOT_DIR}")
message(STATUS "NV_VIDEO_CODEC_SDK_ROOT: ${NV_VIDEO_CODEC_SDK_ROOT}")

