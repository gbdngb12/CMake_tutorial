cmake_minimum_required(VERSION 3.13.4)

project(output)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(submodule)

target_include_directories(${PROJECT_NAME}
    PUBLIC submodule/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE submodule/src
)

target_link_libraries(${PROJECT_NAME} glfw)


