#include "led.h"


#define RED_ON   1 
#define GREEN_ON 0 
static const uint GPIO_PINS[3] = {GPIO_LED1, GPIO_LED2, GPIO_LED3}; // LED引脚数组 / Array of LED GPIO pins


// 设定所有LED初始化/ Initialize all LED GPIOs
void led_init_all(void) {
    for (int i = 0; i < 3; i++) {
        gpio_init(GPIO_PINS[i]);
    }
}

// 熄灭所有LED / Turn off all LEDs
void led_off_all(void) {
    for (int i = 0; i < 3; i++) {
        gpio_set_dir(GPIO_PINS[i], GPIO_IN); // 设为输入高阻态 / Set to input high-impedance
    }
}


void led_green(uint8_t index){
    gpio_init(index);
    gpio_set_dir(index, GPIO_OUT);
    gpio_put(index, GREEN_ON);
}

void led_red(uint8_t index){                    // index is pin number
    gpio_init(index);
    gpio_set_dir(index, GPIO_OUT);
    gpio_put(index, RED_ON);
}

// 置设全部LED初始状态（根据6位pattern）/ Control all LEDs state
void led_control_all(uint8_t pattern) {
    for (int i = 0; i < 3; i++) {
        uint8_t bits = (pattern >> (i * 2)) & 0x03; // 每两位提取一组 / Extract 2 bits per group

        if (bits == 0b01) {
            gpio_set_dir(GPIO_PINS[i], GPIO_OUT);
            gpio_put(GPIO_PINS[i], RED_ON); // 红灯亮 / Turn RED LED ON
        } else if (bits == 0b10) {
            gpio_set_dir(GPIO_PINS[i], GPIO_OUT);
            gpio_put(GPIO_PINS[i], GREEN_ON); // 绿灯亮 / Turn GREEN LED ON
        } else {
            gpio_set_dir(GPIO_PINS[i], GPIO_IN); // 关闭该组LED / Turn OFF the LED group
        }
    }
}

// 翻转单个LED状态 / Toggle current LED states
void led_toggle(int index) {
    gpio_xor_mask(1u << index); // 翻转指定引脚电平 / Toggle pin level 1u = unsigned int 1
}


void led_debugging_red(uint8_t error_codes){

    led_off_all();
    
    if (error_codes & 0b001){
        led_red(GPIO_LED3);
    }
    if (error_codes & 0b010){
        led_red(GPIO_LED2);
    }
    if (error_codes & 0b100){
        led_red(GPIO_LED1);
    }
}

void led_debugging_green(uint8_t error_codes){

    led_off_all();
    
    if (error_codes & 0b001){
        led_green(GPIO_LED3);
    }
    if (error_codes & 0b010){
        led_green(GPIO_LED2);
    }
    if (error_codes & 0b100){
        led_green(GPIO_LED1);
    }
}