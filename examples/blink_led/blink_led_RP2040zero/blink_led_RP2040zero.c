#include <stdio.h>

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include "blink_led_RP2040zero.h"

/* Pico W devices use a GPIO on the WIFI chip for the LED,
 so when building for Pico W, CYW43_WL_GPIO_LED_PIN will be defined*/


int main(){

    stdio_init_all();

    LED_init();

    while (true)
    {
        enable_LED(true);
        sleep_ms(LED_DELAY_MS);
        enable_LED(false);
        sleep_ms(LED_DELAY_MS);
    }
    return 0;
}

void LED_init() {
    // Initialize the CYW43 architecture
    cyw43_arch_init();
}

void enable_LED(bool state){
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, state);
}

