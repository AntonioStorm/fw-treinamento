
add_executable(hello_adc
    hello_adc.c)


# Linka com as bibliotecas padrão
target_link_libraries(hello_adc 
    pico_stdlib 
    hardware_adc
    pico_stdio)

# stdio USB, UF2/bin/elf e cópia para dist/hello_adc.uf2
fw_example_outputs(hello_adc)
