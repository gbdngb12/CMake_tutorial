cmake_minimum_required(VERSION 3.18.1)
project(rapidfuzztest)

#find_library(myrapidfuzz rapidfuzz NAMES rapidfuzz DOC "rapidfuzz library")

find_package(rapidfuzz REQUIRED)

#if(${myrapidfuzz})
#    message(FATAL_ERROR "no rapidfuzz")
#else()
#    message(STATUS "rapidfuzz found! as ${myrapidfuzz}")
#endif()

add_executable(${PROJECT_NAME} main.cpp)

#target_link_libraries(${PROJECT_NAME} ${myrapidfuzz})
target_link_libraries(${PROJECT_NAME} rapidfuzz::rapidfuzz)