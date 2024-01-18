cmake_minimum_required(VERSION 3.27)
project(bc)

set(CMAKE_CXX_STANDARD 23)

add_executable(bc src/bc.cpp
        src/sup/toml.hpp
        src/sup/result.hpp
        src/base.hpp
)
