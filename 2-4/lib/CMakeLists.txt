cmake_minimum_required(VERSION 2.8)
project(newmath)
add_library(newmath adder.cpp)
set_target_properties(newmath PROPERTIES PUBLIC_HEADER adder.h)
install(TARGETS newmath LIBRARY DESTINATION lib
        PUBLIC_HEADER DESTINATION include
        )