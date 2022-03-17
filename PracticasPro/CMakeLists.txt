cmake_minimum_required(VERSION 3.22)
project(MyProject)

add_library(cdatastructures
        # src/fecha.c
        src/fraccion.c
        # src/libro.c
        src/listaDoble.c
        src/pila.c
        # src/punto.c
        src/queue.c
        src/filaDoble.c
        src/cliente.c
        src/moduloDeAtencion.c
        src/myRandom.c
        src/myString.c
        )



add_executable(MyProject main.c)



# target_include_directories(utilities
#         PUBLIC
#         $<INSTALL_INTERFACE:include>
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        
#         PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}/src)
# target_include_directories(generalProgram
#         PUBLIC
#         $<INSTALL_INTERFACE:include>
#         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        
#         PRIVATE
#         ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_include_directories(cdatastructures
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(MyProject PRIVATE cdatastructures)
# target_link_libraries(MyProject PRIVATE utilities)
# target_link_libraries(MyProject PRIVATE generalProgram)

