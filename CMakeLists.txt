cmake_minimum_required(VERSION 3.17)
project(untitled7 C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-pthread")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
add_executable(untitled7 main.c Open_file.c Rotate.c Save_file.c Speaks.c Libr.h)