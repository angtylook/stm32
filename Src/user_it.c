#include "main.h"

#include <stdio.h>

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
    if (GPIO_Pin == GPIO_PIN_0) {
        printf("key1 exti0 \r\n");
    }
}
