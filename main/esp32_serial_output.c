#include "driver/uart.h"
#include "esp_log.h"
#include <string.h>


// Define the ESP32SerialOutput class
typedef struct {
    uart_port_t uart_num;
} ESP32SerialOutput;

// Function to initialize the ESP32SerialOutput
void init_esp32_serial_output(ESP32SerialOutput* esp32_serial_output, uart_port_t uart_num) {
    esp32_serial_output->uart_num = uart_num;

    // Configure UART parameters
    uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };

    // Set UART parameters
    uart_param_config(esp32_serial_output->uart_num, &uart_config);

    // Install UART driver
    uart_driver_install(esp32_serial_output->uart_num, 1024 * 2, 0, 0, NULL, 0);
}

// Function to send temperature and humidity values to the serial output
void send_values(ESP32SerialOutput* esp32_serial_output, float temperature, float humidity) {
    char output[64];
    sprintf(output, "Temperature: %.2f C, Humidity: %.2f%%\n", temperature, humidity);

    // Write the output to the UART
    uart_write_bytes(esp32_serial_output->uart_num, output, strlen(output));
}
