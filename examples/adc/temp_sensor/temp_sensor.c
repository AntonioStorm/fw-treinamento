#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

/* This code is specific for RP2040 zero board and its pinout, since the internal temperature sensor is connected to ADC4,
 which is not available in the external pins of the board.*/

#define ADC4 4  // ADC4 is the internal temperature sensor

void temp_sensor();
void init_temp_sensor();


int main(){
    stdio_init_all();

    // Initialize and the internal temperature sensor channel (ADC4) and the ADC hardware
    init_temp_sensor(); 

    while(true){      
        sleep_ms(500);
        temp_sensor(); 
        sleep_ms(500);
    }
}


//  Running functions

void temp_sensor(){
    
     /* This function selects which ADC channel to read, for this case is not necessary to use the function because we are 
    using only one channel, but it is a good practice to use it in case you want to read from different channels in the future.*/
    adc_select_input(ADC4); 
    
    uint16_t result = adc_read(); // Read the ADC value from the temperature sensor

    /* Convert the ADC value to voltage (The value od 3.236 was measure in my RP2040zero board, it can be different 
    in other boards, the value of 3.3 is the default value in the datasheet)*/ 
    float voltage = result * 3.236f / (1 << 12); 

    // Convert voltage to temperature in Celsius using the formula from the datasheet
    float temperature = 27 - (voltage - 0.706) / 0.001721;

    printf("Temperature: %.2f °C\n", temperature);

    
}

void init_temp_sensor(){
    adc_init(); // Initialize the ADC hardware
    adc_set_temp_sensor_enabled(true); // Enable the internal temperature sensor
}