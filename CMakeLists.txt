cmake_minimum_required(VERSION 3.8)

project(Snake)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Clang-Tidy with modernize and readability checks
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=modernize-*,readability-*")


add_subdirectory (./source/app)
add_subdirectory(./source/core)
add_subdirectory(./source/render)
add_subdirectory(./tests)
add_subdirectory(./external)