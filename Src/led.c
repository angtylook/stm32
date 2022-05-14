#include "led.h"

#include "main.h"
#include <stdio.h>

void LedMain()
{
    int delay = 1500;
    int iter = 0;
    printf("LedMain startup\r\n");
    while (1)
    {
        HAL_GPIO_WritePin(GPIOB, LED_G_Pin, GPIO_PIN_RESET);
        HAL_Delay(delay);
        HAL_GPIO_WritePin(GPIOB, LED_G_Pin, GPIO_PIN_SET);
        HAL_Delay(1000);

        HAL_GPIO_WritePin(GPIOB, LED_B_Pin, GPIO_PIN_RESET);
        HAL_Delay(delay);
        HAL_GPIO_WritePin(GPIOB, LED_B_Pin, GPIO_PIN_SET);
        HAL_Delay(delay);

        HAL_GPIO_WritePin(GPIOB, LED_R_Pin, GPIO_PIN_RESET);
        HAL_Delay(delay);
        HAL_GPIO_WritePin(GPIOB, LED_R_Pin, GPIO_PIN_SET);
        HAL_Delay(delay);
        iter++;
        printf("iter %d\r\n", iter);
    }
}
