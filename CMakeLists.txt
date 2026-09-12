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

add_subdirectory(examples)
