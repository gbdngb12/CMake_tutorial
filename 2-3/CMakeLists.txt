cmake_minimum_required(VERSION 3.13)
project(testsome)
add_executable(testsome main.cpp)
target_link_directories(testsome PRIVATE ${CMAKE_SOURCE_DIR}/../2-2/build/)
target_link_libraries(testsome mymath)
#PRIVATE -> testsome 혼자만 사용한다는뜻