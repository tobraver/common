cmake_minimum_required(VERSION 3.1.0)

project(lib_common C CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# lib
add_library(${PROJECT_NAME} STATIC common.cpp)

# -I
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    .
)

# -L
target_link_directories(
    ${PROJECT_NAME} PUBLIC
)
# -l
target_link_libraries(
    ${PROJECT_NAME} PUBLIC
)

