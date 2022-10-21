set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(${TEST_NAME} ${SRC_FILES})

target_link_libraries(
    ${TEST_NAME} PUBLIC
    ${PROJECT_NAME}
    ${GTEST_LIBRARIES} 
    pthread
)

target_include_directories(${TEST_NAME} PUBLIC
"${CMAKE_SOURCE_DIR}/includes"
"${CMAKE_SOURCE_DIR}")

include(GoogleTest)
gtest_discover_tests(${TEST_NAME})