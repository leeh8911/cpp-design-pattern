FROM ubuntu:20.04

LABEL description="Container for use with Visual Studio" 
LABEL author="leeh8911@gmail.com"

USER root
ARG NUM_CORES=8

ENV DEBIAN_FRONTEND=noninteractive

## Install packages
RUN apt-get update && apt-get upgrade -y && apt-get autoremove -y

# Basics
RUN apt-get install -qq -y ca-certificates
RUN apt-get install -qq -y libgoogle-glog-dev
RUN apt-get install -qq -y libgtest-dev
RUN apt-get install -qq -y automake
RUN apt-get install -qq -y wget
RUN apt-get install -qq -y curl
RUN apt-get install -qq -y unzip
RUN apt-get install -qq -y autoconf
RUN apt-get install -qq -y libtool
RUN apt-get install -qq -y g++ 
RUN apt-get install -qq -y cmake
RUN apt-get install -qq -y git
RUN apt-get install -qq -y clang-format-10
RUN apt-get install -qq -y clang-tidy
# BLAS & LAPACK
RUN apt-get install -qq -y libatlas-base-dev
# Eigen3
RUN apt-get install -qq -y libeigen3-dev
# SuiteSparse and CXSparse (optional)
# - If you want to build Ceres as a *static* library (the default)
#   you can use the SuiteSparse package in the main Ubuntu package
#   repository:
RUN apt-get install -qq -y libsuitesparse-dev
# Sphinx (for documentation)
RUN apt-get install -qq -y sphinx-doc sphinx-common

RUN apt-get install -qq -y clang clang-tidy clang-format
RUN apt-get install -qq -y cppcheck

WORKDIR /tmp
RUN git clone --depth=1 https://ceres-solver.googlesource.com/ceres-solver
WORKDIR /tmp/ceres-solver
RUN mkdir build
WORKDIR /tmp/ceres-solver/build
RUN cmake ..
RUN make -j $NUM_CORES
RUN make test
RUN make install

RUN cd /usr/src/googletest && \
    cmake . && \
    cmake --build . --target install

RUN apt-get install -qq -y flex bison
WORKDIR /tmp
RUN git clone https://github.com/doxygen/doxygen.git
WORKDIR /tmp/doxygen
RUN mkdir build
WORKDIR /tmp/doxygen/build
RUN cmake -G "Unix Makefiles" ..
RUN make
RUN make install

RUN apt install -qq -y graphviz
RUN apt-get install -qq -y npm
RUN npm install mathjax
