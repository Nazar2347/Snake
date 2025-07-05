cmake_minimum_required(VERSION 3.8)

project(Snake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory (./source/app)
add_subdirectory(./source/core)
add_subdirectory(./source/render)
add_subdirectory(./tests)
add_subdirectory(./external)