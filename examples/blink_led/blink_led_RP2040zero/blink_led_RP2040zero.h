#pragma once

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 500
#endif

#define ws2812_PIN 16

static inline void put_pixel(PIO pio, uint sm, uint8_t r, uint8_t g, uint8_t b);
