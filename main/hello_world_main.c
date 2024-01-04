/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <time.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "esp_system.h"
#include "dht22_simulation.h"
#include "esp32_serial_output.h"


void app_main(void)
{
    printf("Hello world!\n");

    // Declare instances of your structures here
    DHT22Simulation dht22_simulation;
    ESP32SerialOutput esp32_serial_output;

    // Initialize the ESP32 serial output (assuming this function initializes the structure)
    init_esp32_serial_output(&esp32_serial_output, UART_NUM_1);

    // Seed the random number generator
    srand((unsigned int)time(NULL));


while (1) {
    // Generate new random temperature and humidity values
    generate_values(&dht22_simulation);

    // Send the new random values to the serial output
    send_values(&esp32_serial_output, dht22_simulation.temperature, dht22_simulation.humidity);

    // Print the new random values to the console as well for debugging
    printf("Randomized Temperature: %.2f°C\n", dht22_simulation.temperature);
    printf("Randomized Humidity: %.2f%%\n", dht22_simulation.humidity);

    // Wait for a while before generating new values
    vTaskDelay(pdMS_TO_TICKS(2000)); // Delay for 2 seconds
}


    /* Print chip information */
    esp_chip_info_t chip_info;
    uint32_t flash_size;
    esp_chip_info(&chip_info);
    printf("This is %s chip with %d CPU core(s), %s%s%s%s, ",
           CONFIG_IDF_TARGET,
           chip_info.cores,
           (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
           (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
           (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
           (chip_info.features & CHIP_FEATURE_IEEE802154) ? ", 802.15.4 (Zigbee/Thread)" : "");

    unsigned major_rev = chip_info.revision / 100;
    unsigned minor_rev = chip_info.revision % 100;
    printf("silicon revision v%d.%d, ", major_rev, minor_rev);
    if(esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
        printf("Get flash size failed");
        return;
    }

    printf("%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
           (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

    printf("Minimum free heap size: %" PRIu32 " bytes\n", esp_get_minimum_free_heap_size());

    for (int i = 10; i >= 0; i--) {
        printf("Restarting in %d seconds...\n", i);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    printf("Restarting now.\n");
    fflush(stdout);
    esp_restart();
}
