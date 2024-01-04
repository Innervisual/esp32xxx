#ifndef ESP32_SERIAL_OUTPUT_H
#define ESP32_SERIAL_OUTPUT_H

#include "driver/uart.h"

typedef struct {
    uart_port_t uart_num;
} ESP32SerialOutput;

void init_esp32_serial_output(ESP32SerialOutput* esp32_serial_output, uart_port_t uart_num);
void send_values(ESP32SerialOutput* esp32_serial_output, float temperature, float humidity);

#endif // ESP32_SERIAL_OUTPUT_H
