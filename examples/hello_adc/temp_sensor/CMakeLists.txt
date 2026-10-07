
add_executable(temp_sensor
    temp_sensor.c)


# Linka com as bibliotecas padrão
target_link_libraries(temp_sensor 
    pico_stdlib 
    hardware_adc
    hardware_gpio
    pico_stdio)

# stdio USB, UF2/bin/elf e cópia para dist/temp_sensor.uf2
fw_example_outputs(temp_sensor)
