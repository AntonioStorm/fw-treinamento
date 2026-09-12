#pragma once

#ifndef LED_DELAY_MS
#define LED_DELAY_MS 100
#endif

#ifndef LED_PIN
#define LED_PIN 16
#endif

void blink(uint pin, bool state);
