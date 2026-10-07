# Mínimo necessário para usar o CMake
cmake_minimum_required(VERSION 3.13)

# Define a placa alvo
set(PICO_BOARD)

# 
set(PICO_SDK_PATH "${CMAKE_CURRENT_LIST_DIR}/3rdparty/pico-sdk")
 
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

# Importa o SDK da Raspberry Pi Pico
include(3rdparty/pico-sdk/external/pico_sdk_import.cmake)

# Nome do projeto e linguagem
project(fw-treinamento C CXX ASM)

# Define o padrão C/C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Inicializa o SDK
pico_sdk_init()

# Pasta onde ficam os binários finais de cada exemplo
set(FW_DIST_DIR "${CMAKE_SOURCE_DIR}/dist")
file(MAKE_DIRECTORY ${FW_DIST_DIR})

# Configura stdio, gera UF2/bin/elf e copia o .uf2 para dist/<target>.uf2
function(fw_example_outputs target)
    pico_enable_stdio_usb(${target} 1)
    pico_enable_stdio_uart(${target} 0)

    pico_add_extra_outputs(${target})

    add_custom_command(
        TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_CURRENT_BINARY_DIR}/${target}.uf2
            ${FW_DIST_DIR}/${target}.uf2)
endfunction()

add_subdirectory(examples)
