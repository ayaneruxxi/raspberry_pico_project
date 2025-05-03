#include "led.h"

// LED引脚数组 / Array of LED GPIO pins
static const uint GPIO_PINS[3] = {GPIO_LED1, GPIO_LED2, GPIO_LED3};

// 红灯点亮时的电平定义 / Level when RED LED is ON
#define RED_ON_LEVEL   0
// 绿灯点亮时的电平定义 / Level when GREEN LED is ON
#define GREEN_ON_LEVEL 1

// LED显示模式 / LED display mode
typedef enum {
    LED_OFF = 0b00,   // 熄灭 / OFF
    LED_RED = 0b01,   // 红灯亮 / RED ON
    LED_GREEN = 0b10  // 绿灯亮 / GREEN ON
} led_color_t;

// 初始化所有LED引脚 / Initialize all LED GPIOs
void led_init(void) {
    for (int i = 0; i < 3; i++) {
        gpio_init(GPIO_PINS[i]);
        gpio_set_dir(GPIO_PINS[i], GPIO_OUT);
        gpio_put(GPIO_PINS[i], GREEN_ON_LEVEL); // 默认设置为灭灯 / Default OFF (GREEN_ON_LEVEL)
    }
}

// 熄灭所有LED / Turn off all LEDs
void led_all_off(void) {
    for (int i = 0; i < 3; i++) {
        gpio_set_dir(GPIO_PINS[i], GPIO_IN); // 设为输入高阻态 / Set to input high-impedance
    }
}

// 设置LED初始状态（根据6位pattern）/ Set initial LED state (according to 6-bit pattern)
void led_control(uint8_t pattern, bool toggle) {
    for (int i = 0; i < 3; i++) {
        uint8_t bits = (pattern >> (i * 2)) & 0x03; // 每两位提取一组 / Extract 2 bits per group

        if (bits == LED_RED) {
            gpio_set_dir(GPIO_PINS[i], GPIO_OUT);
            gpio_put(GPIO_PINS[i], RED_ON_LEVEL); // 红灯亮 / Turn RED LED ON
        } else if (bits == LED_GREEN) {
            gpio_set_dir(GPIO_PINS[i], GPIO_OUT);
            gpio_put(GPIO_PINS[i], GREEN_ON_LEVEL); // 绿灯亮 / Turn GREEN LED ON
        } else {
            gpio_set_dir(GPIO_PINS[i], GPIO_IN); // 关闭该组LED / Turn OFF the LED group
        }
    }
}

// 翻转LED状态 / Toggle current LED states
void led_toggle(void) {
    for (int i = 0; i < 3; i++) {
        gpio_xor_mask(1u << GPIO_PINS[i]); // 翻转指定引脚电平 / Toggle pin level 1u = unsigned int 1
    }
}
