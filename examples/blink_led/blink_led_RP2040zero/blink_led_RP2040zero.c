/* The board RP2040zero uses a RGB LED that is controlled by w2812, you can 
have more information in https://github.com/raspberrypi/pico-examples/blob/master/pio/ws2812/ws2812.pio#L36-L52$0*/

#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "blink_led_RP2040zero.h"
#include "ws2812.pio.h"   // gerado pelo CMake a partir do .pio

#define WS2812_PIN 16



int main() {
    PIO pio = pio0;
    uint sm = pio_claim_unused_sm(pio, true);
    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, false);

    while (true) {
        put_pixel(pio, sm, 16, 5, 11);  sleep_ms(500);  // vermelho
        put_pixel(pio, sm, 0, 16, 0);  sleep_ms(500);  // verde
        put_pixel(pio, sm, 0, 0, 16);  sleep_ms(500);  // azul
    }
}


static inline void put_pixel(PIO pio, uint sm, uint8_t r, uint8_t g, uint8_t b) {
    uint32_t grb = ((uint32_t)g << 16) | ((uint32_t)r << 8) | b;
    pio_sm_put_blocking(pio, sm, grb << 8);   // dado nos 24 bits altos
}


