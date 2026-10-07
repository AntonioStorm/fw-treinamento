
add_executable(blink_led_pico
    blink_led_pico.c)


# Linka com as bibliotecas padrão
target_link_libraries(blink_led_pico 
    pico_stdlib 
    hardware_adc
    hardware_gpio
    pico_stdio)

# stdio USB, UF2/bin/elf e cópia para dist/blink_led_pico.uf2
fw_example_outputs(blink_led_pico)
