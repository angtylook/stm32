#include "key.h"

#include "main.h"
#include <stdio.h>

int Key2State() {
    if (HAL_GPIO_ReadPin(KEY_2_GPIO_Port, KEY_2_Pin) == GPIO_PIN_SET) {
        while(HAL_GPIO_ReadPin(KEY_2_GPIO_Port, KEY_2_Pin) == GPIO_PIN_SET) {
            ;  // wait for release
        }
        return KEY_ON;
    } else {
        return KEY_OFF;
    }
}

void KeyMain() {
    printf("KeyMain startup\r\n");
    int led[3] = {LED_R_Pin, LED_G_Pin, LED_B_Pin};
    int pin = 0;
    HAL_GPIO_WritePin(GPIOB, led[pin], GPIO_PIN_RESET);
    while(1) {
        if(Key2State() == KEY_OFF) {
            continue;
        }
        printf("set led pin %d\r\n", pin);
        HAL_GPIO_WritePin(GPIOB, led[pin], GPIO_PIN_SET);
        pin = (pin + 1) % 3;
        HAL_GPIO_WritePin(GPIOB, led[pin], GPIO_PIN_RESET);
    }
}
