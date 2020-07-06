FROM ubuntu:18.04 
RUN apt-get update  && apt-get install  -y \
    build-essential \
    curl \
    git \
    libpcre3-dev \
    python3-dev \
    wget \
    libjpeg-dev \
    vim


# cmake 3.15.4.
RUN cd /tmp \
    && wget -nv https://github.com/Kitware/CMake/releases/download/v3.15.4/cmake-3.15.4-Linux-x86_64.tar.gz \
    && tar -xzf cmake-3.15.4-Linux-x86_64.tar.gz -C /usr/local/share \
    && ln -s /usr/local/share/cmake-3.15.4-Linux-x86_64/bin/cmake /usr/bin/cmake

# eigen
RUN mkdir -p /tmp && cd /tmp \
    && wget -nv http://bitbucket.org/eigen/eigen/get/3.3.7.tar.gz \
    && tar -xvf 3.3.7.tar.gz \
    && cd eigen-eigen-323c052e1731 && cmake -S . -B ./build \
    && cd build && make install

#RUN

COPY main.cpp CMakeLists.txt FindEIGEN.cmake /tmp/motesque-build/

RUN cd /tmp/motesque-build/ \
    && cmake -S . -B ./build  \
    && cd ./build && make && make install

# 