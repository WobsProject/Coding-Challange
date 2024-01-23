#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define ledPin 13

void taskLED(void *param);

void app_main(void) {
    xTaskCreate(taskLED, "Task LED", 1024, NULL, 3, NULL);
}

void taskLED(void *param){
    esp_rom_gpio_pad_select_gpio(ledPin);
    gpio_set_direction(ledPin, GPIO_MODE_OUTPUT);

    while(1){
        gpio_set_level(ledPin, 1);
        vTaskDelay(1000/ portTICK_PERIOD_MS);
        gpio_set_level(ledPin, 0);
        vTaskDelay(4000/ portTICK_PERIOD_MS);

        gpio_set_level(ledPin, 1);
        vTaskDelay(2000/ portTICK_PERIOD_MS);
        gpio_set_level(ledPin, 0);
        vTaskDelay(3000/ portTICK_PERIOD_MS);

        gpio_set_level(ledPin, 1);
        vTaskDelay(3000/ portTICK_PERIOD_MS);
        gpio_set_level(ledPin, 0);
        vTaskDelay(2000/ portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}