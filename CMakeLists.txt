# Mínimo necessário para usar o CMake
cmake_minimum_required(VERSION 3.13)

# Importa o SDK da Raspberry Pi Pico (ver abaixo como fazer isso funcionar)
include(3rdparty/pico_sdk_import.cmake)

# Nome do projeto e linguagem
project(blink_led C CXX ASM)

# Define o padrão C/C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Inicializa o SDK
pico_sdk_init()

# Adiciona o executável
add_executable(blink_led
    examples/blink_led/src/main.c
)

# Linka com as bibliotecas padrão
target_link_libraries(blink_led 
    pico_stdlib 
    # hardware_adc
    pico_stdio)


pico_enable_stdio_usb(blink_led 1)
pico_enable_stdio_uart(blink_led 0)

# Gera UF2, bin, elf, etc.
pico_add_extra_outputs(blink_led)

# Move .uf2 file to dist/ directory
add_custom_command(
   TARGET blink_led POST_BUILD  
   COMMAND ${CMAKE_COMMAND} -E rename
   ${CMAKE_BINARY_DIR}/blink_led.uf2
  ${CMAKE_SOURCE_DIR}/dist/blink_led.uf2) 