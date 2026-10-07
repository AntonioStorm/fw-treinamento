
add_executable(hello_pwm
    hello_pwm.c)


# Linka com as bibliotecas padrão
target_link_libraries(hello_pwm 
    pico_stdlib 
    hardware_pwm
    pico_stdio)

# stdio USB, UF2/bin/elf e cópia para dist/hello_pwm.uf2
fw_example_outputs(hello_pwm)
