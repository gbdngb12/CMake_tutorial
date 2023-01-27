cmake_minimum_required(VERSION 2.8)
project(myprint)
add_library(myprint myprint.cpp)
set_target_properties(myprint PROPERTIES PUBLIC_HEADER myprint.h)
