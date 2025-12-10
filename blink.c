#include "pico/stdlib.h"
#include <stdio.h>

// LED pin configuration
// Pico: GPIO 25 (onboard LED)
// Pico W: GPIO 0 (needs different setup via cyw43)
#ifndef LED_PIN
#define LED_PIN 25
#endif

// Configurable blink timing (milliseconds)
#ifndef BLINK_ON_TIME
#define BLINK_ON_TIME 500
#endif

#ifndef BLINK_OFF_TIME
#define BLINK_OFF_TIME 500
#endif

int main() {
    // Initialize standard I/O for USB serial debugging
    stdio_init_all();
    
    // Small delay to allow USB connection to establish
    sleep_ms(2000);
    
    printf("Pico Blink Starting...\n");
    printf("LED Pin: %d\n", LED_PIN);
    printf("Blink Rate: %dms ON, %dms OFF\n", BLINK_ON_TIME, BLINK_OFF_TIME);
    
    // Initialize GPIO for LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    printf("GPIO initialized successfully\n");
    
    uint32_t blink_count = 0;
    
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(BLINK_ON_TIME);
        gpio_put(LED_PIN, 0);
        sleep_ms(BLINK_OFF_TIME);
        
        blink_count++;
        if (blink_count % 10 == 0) {
            printf("Blink count: %lu\n", blink_count);
        }
    }
    
    return 0;
}
