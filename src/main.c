#include <stdio.h>
#include "pico/stdlib.h"
#include "led.h"
#include "error_code.h"


bool toggle = 0;                          // 是否启用交替闪烁 / Enable toggle (true/false)


int main() {

    stdio_init_all();
    led_init_all();                 


    while (true) {
        if (toggle) {
            led_toggle(GPIO_LED1); 
        }
        sleep_ms(500);

        led_debugging_green(3);
    }

}