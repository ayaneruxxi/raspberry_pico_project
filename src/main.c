#include <stdio.h>
#include "pico/stdlib.h"
#include "led.h"

int main() {
    //stdio_init_all();
    led_init(); // 初始化LED / Initialize LEDs

    uint8_t pattern = 0b000101;  // 6位二进制：低位代表LED1/ Third GREEN, second RED, first RED
    bool toggle = true;          // 是否启用交替闪烁 / Enable toggle (true/false)

    led_control(pattern); // 先设置初始LED状态，不进行翻转 / Set initial LED state, no toggle

    while (true) {
        if (toggle) {
            led_toggle(GPIO_LED1); // 每500ms翻转LED状态 / Toggle LEDs every 500ms
            led_toggle(GPIO_LED2); // 每500ms翻转LED状态 / Toggle LEDs every 500ms

        }
        sleep_ms(500); // 延迟500ms / Delay 500ms
    }
}
