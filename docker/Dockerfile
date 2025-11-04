FROM nvidia/cuda:13.0.1-cudnn-devel-ubuntu22.04
RUN apt update && apt install -y cmake 
RUN ln -s /usr/lib/x86_64-linux-gnu/libnvcuvid.so.1 /usr/lib/x86_64-linux-gnu/libnvcuvid.so
WORKDIR  /code/src
COPY src /code/src
