cmake_minimum_required(VERSION 3.13)
project(test)
add_executable(test main.cpp)
target_link_libraries(test newmath)