#pragma once

// Other methodo is to do #ifndef HEELO_ADC_H but #pragma once is more modern and less error-prone

#define ADC0 26 // ADC0 is connected to GPIO26
#define ADC1 27 // ADC1 is connected to GPIO27
#define ADC2 28 // ADC2 is connected to GPIO28

void read_and_transform_adc(uint pin);