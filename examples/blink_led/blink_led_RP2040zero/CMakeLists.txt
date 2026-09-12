
add_executable(fw-treinamento
    blink_led_RP2040zero.c)


# Linka com as bibliotecas padrão
target_link_libraries(fw-treinamento 
    pico_stdlib
    pico_cyw43_arch_none) 
    

pico_enable_stdio_usb(fw-treinamento 1)
pico_enable_stdio_uart(fw-treinamento 0)

# Gera UF2, bin, elf, etc.
pico_add_extra_outputs(fw-treinamento)

# Move .uf2 file to dist/ directory
add_custom_command(
   TARGET fw-treinamento POST_BUILD  
   COMMAND ${CMAKE_COMMAND} -E rename
   ${CMAKE_CURRENT_BINARY_DIR}/fw-treinamento.uf2
  ${CMAKE_SOURCE_DIR}/dist/fw-treinamento.uf2) 