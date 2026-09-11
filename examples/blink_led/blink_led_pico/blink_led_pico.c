#include "pico/stdlib.h"
#include <stdio.h>

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 100
#endif

#define LED_PIN 16

void Blink(const uint LED){
    gpio_put(LED, 1);
    sleep_ms(LED_DELAY_MS);
    gpio_put(LED, 0);
    sleep_ms(LED_DELAY_MS);
}

int main(){
    
    stdio_init_all();
    const uint LED = LED_PIN;
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    while(true){

        Blink(LED);
        
    }

}