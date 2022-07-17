cmake_minimum_required(VERSION 3.22)
project(Hurokul)

set(CMAKE_CXX_STANDARD 20)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/hurokul/*.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/hurokul/*.h)

add_executable(hurokul ${sources})

