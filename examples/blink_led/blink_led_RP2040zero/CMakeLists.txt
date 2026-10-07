
add_executable(blink_led_RP2040zero
    blink_led_RP2040zero.c)

pico_generate_pio_header(blink_led_RP2040zero ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio)

# Linka com as bibliotecas padrão
target_link_libraries(blink_led_RP2040zero 
    pico_stdlib
    hardware_pio
    )

# stdio USB, UF2/bin/elf e cópia para dist/blink_led_RP2040zero.uf2
fw_example_outputs(blink_led_RP2040zero)
