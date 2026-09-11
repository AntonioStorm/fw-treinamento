#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

// This code is specific for RP2040 zero board and its pinout

#define ADC0 26 // ADC0 is connected to GPIO26
#define ADC1 27 // ADC1 is connected to GPIO27
#define ADC2 28 // ADC2 is connected to GPIO28

void read_and_transform_adc(uint pin);


int main(){
    stdio_init_all();

    adc_init(); // Initialize the ADC hardware

    adc_gpio_init(ADC0); // Initialize an specific ADC channel (ADC0 in this case)

    while(true){
        sleep_ms(500);
        read_and_transform_adc(ADC0); // Read and transform the ADC value from the selected channel
        sleep_ms(500);
    }
}

//  Running functions

void read_and_transform_adc(uint pin){
    
    /* This function selects which ADC channel to read, for this case is not necessary to use the function because we are 
    using only one channel, but it is a good practice to use it in case you want to read from different channels in the future.*/
    adc_select_input(pin - ADC0); 
    
    uint16_t result = adc_read();
   
    /* The value of 3.236 was measured in my RP2040zero board, it can be different in other boards, the value of 3.3 is the 
    default value in the datasheet.*/

    // Convert the ADC value to voltage (assuming a 12-bit ADC and a reference voltage of 3.3V)
    float voltage = result * 3.236f / (1 << 12); 

    printf("Voltage: %.2f V\n", voltage);    
}