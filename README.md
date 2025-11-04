# NVIDIA Video Decoder Caps Test

This project is designed to verify whether the `cuvidGetDecoderCaps` function can return successfully when testing NVIDIA Video Codec SDK.

## Prerequisites

- Docker with NVIDIA Container Runtime support
- NVIDIA GPU with video decoding capabilities
- NVIDIA Driver installed( driver version : 580.82.09 )

## Building the Docker Image

The base image is built on `nvidia/cuda:13.0.1-cudnn-devel-ubuntu22.04` with additional required libraries.

```bash
docker build -f docker/Dockerfile -t nvidia-decoder:v1 .
```

## Running the Container

1. Start the container with GPU support:
```bash
docker run -it --runtime=nvidia --name decoder-0 --env NVIDIA_VISIBLE_DEVICES=0 -e NVIDIA_DRIVER_CAPABILITIES=video,compute,utility nvidia-decoder:v1
```

2. Enter the running container:
```bash
docker exec -it decoder-0 bash
```

## Building and Running Inside the Container

1. Build the project:
```bash
cd /code/src && mkdir -p build && cd build && cmake .. && make
```

2. Run the test program:
```bash
cd /code/src/build && ./test_decoder_caps
```

## Project Structure

- `src/test_decoder_caps.cpp` - Main test program that queries decoder capabilities
- `src/CMakeLists.txt` - CMake build configuration
- `docker/Dockerfile` - Docker image definition

## Default Build Configuration

The project is configured to build in Debug mode by default, which includes debug symbols (`-g`) and no optimization (`-O0`) for easier debugging.

## Testing

The program tests H.264 8-bit 420 decoder capabilities and outputs:
- `bIsSupported` - Whether the codec is supported
- `nNumNVDECs` - Number of available NVDEC units
- `nOutputFormatMask` - Supported output formats
- `nMaxWidth` / `nMaxHeight` - Maximum resolution
- `nMinWidth` / `nMinHeight` - Minimum resolution
- `nMaxMBCount` - Maximum macroblock count


