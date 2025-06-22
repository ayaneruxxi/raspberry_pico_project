#ifndef LED_H_
#define LED_H_

#include "pico/stdlib.h"
#include <stdbool.h>

// 定义LED引脚 / Define LED GPIO pins
#define GPIO_LED1 11
#define GPIO_LED2 14
#define GPIO_LED3 15



// 函数声明 / Function declarations
void led_init_all(void);                        // 初始化LED引脚 / Initialize LED GPIOs
void led_off_all(void);                     // 熄灭所有LED / Turn off all LEDs

void led_green(uint8_t index);              // 设置单个LED绿色/ Control single LED green
void led_green(uint8_t index);              // 设置单个LED红/ Control single LED red

void led_control_all(uint8_t pattern);      // 设置LED初始状态 / Set initial LED state
void led_toggle(int index);                 // 翻转LED当前状态 / Toggle LED states

#endif // LED_H_