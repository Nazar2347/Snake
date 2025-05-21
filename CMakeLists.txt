cmake_minimum_required(VERSION 3.8)

project(Snake)

set(CMAKE CXX_STANDARD 23)
set(CMAKE CXX_STANDARD_REQUIRED ON)
set(CMAKE CXX_EXTENSIONS OFF)

add_subdirectory (./source/app)
add_subdirectory(./source/core)
add_subdirectory(./source/render)