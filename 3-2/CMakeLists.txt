cmake_minimum_required(VERSION 3.13.4)

project(output VERSION 1.0)

configure_file(outputConfig.h.in outputConfig.h)

add_executable(${PROJECT_NAME} main.cpp)

#header파일을 위해 설정
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(submodule)

# DOWNLOAD ALL THE SUBMODULES
find_Package(Git QUIET)
if(GIT_FOUND AND EXISTS "{PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE) 
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init -recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE_GIT_SUBMOD_RESULT)
        if(NOT_GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

#   CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/submodules/CMakeLists.txt")
    message(FATAL ERROR "The glfw submodules was not downloaded! GIT SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC submodule/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE submodule/src
)

target_link_libraries(${PROJECT_NAME} glfw)
