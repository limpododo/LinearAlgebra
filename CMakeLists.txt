cmake_minimum_required(VERSION 3.27)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE
        inc/*.h
        src/*.hpp
        src/*.cpp)

add_executable(LinearAlgebra ${SOURCE})
include_directories(inc/)
