# NVIDIA Video Decoder Caps 测试流程
# 创建基于运行镜像，基础镜像是在nvidia/cuda:13.0.1-cudnn-devel-ubuntu22.04基础镜像内增加相关基础库
    docker build -f docker/Dockerfile -t nvidia-decoder:v1 .
# 启动基础镜像并运行程序
    1、docker run -it --runtime=nvidia --name decoder-0 --env NVIDIA_VISIBLE_DEVICES=0 -e NVIDIA_DRIVER_CAPABILITIES=video,compute,utility nvidia-decoder:v1
    2、docker exec -it decoder-0 bash 
##  在容器中运行程序
    1、cd /code/src && mkdir build && cd build && cmake .. && make 
    2、cd /code/src/build && ./test_decoder_caps

