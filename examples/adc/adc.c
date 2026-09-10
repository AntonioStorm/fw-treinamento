#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/gpio.h"

#define ADC0 26 // ADC0 is connected to GPIO26
#define ADC1 27 // ADC1 is connected to GPIO27
#define ADC2 28 // ADC2 is connected to GPIO28
#define ADC4 4  // ADC4 is the internal temperature sensor

void read_and_transform_adc(uint pin);

void temp_sensor();


int main(){
    
    stdio_init_all();
    adc_init(); // Initialize the ADC hardware

    adc_gpio_init(ADC0); // Initialize and select an specific ADC channel (ADC0 in this case)

    adc_set_temp_sensor_enabled(true);; // Initialize and select the internal temperature sensor channel (ADC4)

    while(true){

        read_and_transform_adc(ADC0); // Read and transform the ADC value from the selected channel
        
        temp_sensor(); // Read and transform the ADC value from the internal temperature sensor channel

    }

}


//  Running functions

void read_and_transform_adc(uint pin){
    
    adc_select_input(pin - ADC0); 
    
    uint16_t result = adc_read();
    
    float voltage = result * 3.236f / (1 << 12); // Convert the ADC value to voltage (assuming a 12-bit ADC and a reference voltage of 3.3V)

    printf("Voltage: %.2f V\n", voltage);

    sleep_ms(500);
}

void temp_sensor(){
    
    adc_select_input(ADC4); // Select the ADC channel based on the pin number (ADC0 corresponds to channel 0, ADC1 to channel 1, etc.)

    uint16_t result = adc_read(); // Read the ADC value from the temperature sensor
    float voltage = result * 3.236f / (1 << 12); // Convert the ADC value to voltage (The value od 3.236 was measure in my RP2040zero board, it can be different in other boards, the value of 3.3 is the default value in the datasheet)

    // Convert voltage to temperature in Celsius using the formula from the datasheet
    float temperature = 27 - (voltage - 0.706) / 0.001721;

    printf("Temperature: %.2f °C\n", temperature);

    sleep_ms(500);
    
}
