#include <stdio.h>
#include "pico/stdlib.h"
#include "led.h"
#include "error_code.h"

static const uint8_t pattern = ERR_NONE;  // 6位二进制：低位代表LED1/ Third GREEN, second RED, first RED
bool toggle = true;                          // 是否启用交替闪烁 / Enable toggle (true/false)


int main() {

    led_init_all();                 // 设置初始LED状态/ Set initial LED state
    led_green(GPIO_LED1);
    led_green(GPIO_LED2);

    while (true) {
        if (toggle) {
            led_toggle(GPIO_LED1); 
        }
        sleep_ms(500);
    }

}