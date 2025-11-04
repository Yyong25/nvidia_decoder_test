# NVIDIA Video Decoder Caps 测试工程

这是一个用于测试 NVIDIA Video Codec SDK 中 `cuvidGetDecoderCaps` API 的测试demo。

## 功能说明

该测试demo实现了以下功能：
1. 初始化CUDA驱动和NVDEC
2. 创建CUDA上下文
3. 使用 `cuvidGetDecoderCaps` 查询不同编解码器的解码器能力
4. 使用 `AutoResource` 类进行RAII管理，确保CUDA上下文正确弹出

## 代码结构

- `test_decoder_caps.cpp`: 主测试程序
- `CMakeLists.txt`: CMake构建配置文件

## 编译要求

- CUDA Toolkit (需要包含CUDA驱动API)
- NVIDIA Video Codec SDK
- CMake 3.10或更高版本
- C++17或更高版本的编译器

## 编译步骤

1. 创建构建目录：
```bash
cd nvidia_decoder_test
mkdir build
cd build
cmake ..
make 
```

2. 运行测试：
```bash
./test_decoder_caps
```

## 测试内容

程序会测试以下编解码器配置：
1. H.264 8-bit 420

每个测试会输出以下信息：
- 是否支持该编解码器配置
- 支持的最大/最小分辨率
- 支持的输出格式
- 直方图支持情况
- 其他相关能力信息



