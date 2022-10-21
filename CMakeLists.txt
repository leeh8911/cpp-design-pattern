cmake_minimum_required(VERSION 3.11.3)

project(CPP_DESIGN_PATTERN)

message("${CMAKE_CURRENT_BINARY_DIR}")

set(PROJECT_NAME CPP_DESIGN_PATTERN)
set(TEST_NAME CPP_DESIGN_PATTERN_TEST)

# Set the C++ standard we will use
set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_CXX_STANDARD 17)

option(OPTION_BUILD_DOCS		"Build documentation."										OFF)

find_program(CLANGTIDY clang-tidy)
if(CLANGTIDY)
message(STATUS "activate clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "${CLANGTIDY};-extra-arg=-Wno-unknown-warning-option;-header-filter=${CMAKE_SOURCE_DIR}/src/*;-fix")
else()
message(SEND_ERROR "clang-tidy requested but executable not found")
endif()


add_subdirectory(src)

add_subdirectory(test)

add_dependencies(${TEST_NAME} ${PROJECT_NAME})

if(OPTION_BUILD_DOCS)
message(STATUS "Build documentation open")
include(cmake/build_doxygen.cmake)
build_doxygen()
endif()