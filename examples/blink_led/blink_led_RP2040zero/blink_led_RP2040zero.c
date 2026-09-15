#include <stdio.h>

#include "pico/stdlib.h"
#include "blink_led_RP2040zero.h"

/* The board RP2040zero uses a RGB LED that is controlled by w2812, you can 
have more information in https://github.com/raspberrypi/pico-examples/blob/master/pio/ws2812/ws2812.pio#L36-L52$0*/

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
    ;
}

void enable_LED(bool state){
    ;
}

