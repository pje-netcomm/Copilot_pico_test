cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Enable compile warnings
add_compile_options(-Wall -Wextra)

pico_sdk_init()

add_executable(blink
    blink.c
)

# Link required libraries
target_link_libraries(blink 
    pico_stdlib
)

# Generate additional output files (UF2, hex, bin)
pico_add_extra_outputs(blink)
