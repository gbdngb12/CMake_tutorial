cmake_minimum_required(VERSION 2.8)
project(dong)
add_executable(dong main.cpp)
install(TARGETS dong DESTINATION bin)
#bin -> /usr/local/bin