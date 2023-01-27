cmake_minimum_required(VERSION 3.13.4)

project(output VERSION 1.0)

# 옵션 설정
option(USE_MYPRINT "A Simple Library Print username" ON)
if(USE_MYPRINT)
    add_subdirectory(MyPrint)
    list(APPEND EXTRA_LIB_DIRS "MyPrint")
    list(APPEND EXTRA_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/MyPrint")
    list(APPEND EXTRA_LINKS myprint)
    #target_include_directories(${PROJECT_NAME}
    #    PUBLIC myprint
    #)
    #target_link_directories(${PROJECT_NAME}
    #    PUBLIC myprint
    #)
endif()

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
    ${EXTRA_INCLUDE_DIRS}
)

target_link_directories(${PROJECT_NAME}
    PRIVATE submodule/src
    ${EXTRA_LIBS_DIRS}
)

target_link_libraries(${PROJECT_NAME} ${EXTRA_LINKS} glfw)
