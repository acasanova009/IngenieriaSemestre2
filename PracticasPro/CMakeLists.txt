cmake_minimum_required(VERSION 3.22)
project(MyProject)

add_library(cdataStructures
        src/fraccion.c
        src/queue.c
        src/punto.c
        )

add_executable(MyProject main.c)

target_include_directories(cdataStructures
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(MyProject PRIVATE cdataStructures)

