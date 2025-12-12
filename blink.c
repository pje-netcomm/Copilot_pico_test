#include "pico/stdlib.h"

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
    // Initialize GPIO for LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    // Blink LED forever
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(BLINK_ON_TIME);
        gpio_put(LED_PIN, 0);
        sleep_ms(BLINK_OFF_TIME);
    }
    
    return 0;
}
