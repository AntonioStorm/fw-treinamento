#pragma once

#define ADC4 4  // ADC4 is the internal temperature sensor

#ifndef DELAY_MS
#define DELAY_MS 500
#endif

void temp_sensor();
void init_temp_sensor();