#include "util.h"

static UART_HandleTypeDef *print_uart_handle;

void SetPrintUartHandle(UART_HandleTypeDef* huart) {
    print_uart_handle = huart;
}

#ifdef __GNUC__
int _write(int fd, char *ptr, int len)
{
    if (print_uart_handle != NULL)
    {
        HAL_UART_Transmit(print_uart_handle, (uint8_t *)ptr, len, 0xFFFF);
    }
    return len;
}
#endif
