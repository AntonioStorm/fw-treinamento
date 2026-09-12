#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include <stdio.h>
#include "hello_pwm.h"


int main() {
    stdio_init_all();

    // Set GPIO 0 ans 1 as PWM output
    
    gpio_set_function(0, GPIO_FUNC_PWM);
    gpio_set_function(1, GPIO_FUNC_PWM);

    // Get the PWM slice number for the specified GPIO
    uint slice_num = pwm_gpio_to_slice_num(0);

    // Set the PWM frequency and duty cycle
    pwm_set_wrap(slice_num, 1000); // Set the wrap value (period)
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 100); // Set the duty cycle 
    pwm_set_chan_level(slice_num, PWM_CHAN_B, 500); // Set the duty cycle 
    
    // Enable the PWM output
    pwm_set_enabled(slice_num, true);

    while (true) {
        // The main loop can be used to adjust the duty cycle or perform other tasks
        sleep_ms(DELAY_MS);
    }

    return 0;
}



