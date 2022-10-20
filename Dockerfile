FROM ubuntu:20.04

LABEL description="Container for use with Visual Studio" 
LABEL author="leeh8911@gmail.com"

USER root
ARG NUM_CORES=8

ENV DEBIAN_FRONTEND=noninteractive

# Basics
RUN apt-get update && apt-get install -qq -y -f --no-install-recommends \
    # Base dependencies
    ca-certificates libgoogle-glog-dev \
    libgtest-dev automake wget curl unzip autoconf libtool g++ gcc make \
    cmake git \
    # BLAS & LAPACK
    libatlas-base-dev \
    # Eigen3
    libeigen3-dev \
    # SuiteSparse and CXSparse (optional)
    # - If you want to build Ceres as a *static* library (the default)
    #   you can use the SuiteSparse package in the main Ubuntu package
    #   repository:
    libsuitesparse-dev \
    # Sphinx (for documentation)
    sphinx-doc sphinx-common \
    # code linter and formatter
    cppcheck clang clang-tidy clang-format \
    # For doxygen
    graphviz npm flex bison && \
    mkdir temp && cd temp && \
    git clone --depth=1 https://ceres-solver.googlesource.com/ceres-solver && \
    cd ceres-solver && mkdir build && cd build && \
    cmake .. && make -j $NUM_CORES && make test && make install && \
    cd ../../ && \
    git clone https://github.com/doxygen/doxygen.git && \
    cd doxygen && mkdir build && cd build && \
    cmake -G "Unix Makefiles" .. && make && make install && \
    cd ../../ && \
    git clone https://github.com/google/googletest.git && \
    cd googletest && mkdir build && cd build && \
    cmake .. && \
    cmake --build . --target install && \
    apt-get autoremove -y && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*
RUN npm install mathjax
