# cmake_minimum_required(VERSION <specify CMake version here>)
cmake_minimum_required(VERSION 3.13)
project(3-uzd)



set(CMAKE_CXX_STANDARD 14)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)


add_executable(3-uzd
        main.cpp
        fun.cpp
        fun.h
        )
target_link_libraries(3-uzd gtest gtest_main)
