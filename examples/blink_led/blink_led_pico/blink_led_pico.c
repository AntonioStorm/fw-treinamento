#include "pico/stdlib.h"
#include <stdio.h>

#include "blink_led_pico.h"


int main(){
    stdio_init_all();


    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while(true){
        blink(LED_PIN, true);
        sleep_ms(LED_DELAY_MS);
        blink(LED_PIN, false);
        sleep_ms(LED_DELAY_MS);
    }
}

void blink(uint pin, bool state){
    gpio_put(pin, state);

}