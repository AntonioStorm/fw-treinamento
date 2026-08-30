#include "pico/stdlib.h"
#include <stdio.h>



void Blink(const uint LED){
    gpio_put(LED, 1);
    sleep_ms(100);
    gpio_put(LED, 0);
    sleep_ms(100);
}

int main(){
    
    stdio_init_all();
    const uint LED = 25;
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);

    while(true){
        Blink(LED);
        sleep_ms(100);
    }

}