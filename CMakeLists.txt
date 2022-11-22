cmake_minimum_required(VERSION 3.11.3)

project(CPP_DESIGN_PATTERN)

message("${CMAKE_CURRENT_BINARY_DIR}")

set(PROJECT_NAME CPP_DESIGN_PATTERN)
set(TEST_NAME CPP_DESIGN_PATTERN_TEST)

set(CMAKE_MODULE_PATH 
    ${CMAKE_MODULE_PATH} 
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Set the C++ standard we will use
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

option(OPTION_BUILD_DOCS "Build documentation." OFF)
option(OPTION_TEST_ALL "Execute all test" OFF)

if (OPTION_TEST_ALL)
add_compile_definitions(TEST_ALL)
endif(OPTION_TEST_ALL)

find_program(CLANGTIDY clang-tidy)
if(CLANGTIDY)
message(STATUS "activate clang-tidy")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "${CLANGTIDY};-extra-arg=-Wno-unknown-warning-option;-header-filter=${CMAKE_SOURCE_DIR}/src/*;-fix")
else()
message(SEND_ERROR "clang-tidy requested but executable not found")
endif()

message(STATUS ${OPTION_BUILD_DOCS})
message(STATUS OPTION_BUILD_DOCS)

if(OPTION_BUILD_DOCS)
message(STATUS "Build only documentation")
add_subdirectory(docs)
else()
message(STATUS "Build source and test files")
add_subdirectory(src)
add_subdirectory(test)
add_dependencies(${TEST_NAME} ${PROJECT_NAME})
endif()


