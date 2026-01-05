cmake_minimum_required(VERSION 3.10)
project(comprobacion)

# ESTO EVITA QUE BUSQUE LIBRERÍAS DE NVIDIA O INTEL
set(BLA_VENDOR "Generic") 

find_package(LAPACK REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE ${LAPACK_LIBRARIES})
target_link_options(main PRIVATE "-static")