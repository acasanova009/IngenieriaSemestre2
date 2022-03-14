cmake_minimum_required(VERSION 3.22)
project(MyProject)

add_library(cdatastructures
        # src/cliente.c
        # src/fecha.c
        src/fraccion.c
        # src/libro.c
        src/listaDoble.c
        # src/moduloDeAtencion.c
        src/myRandom.c
        src/myString.c
        src/pila.c
        # src/punto.c
        src/queue.c
        src/queueDoble.c
        )

add_executable(MyProject main.c)

target_include_directories(cdatastructures
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(MyProject PRIVATE cdatastructures)

