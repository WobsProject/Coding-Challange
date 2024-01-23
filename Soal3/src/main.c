#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define ledPin 13

char *alphabet[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
int x, y;

void taskAlphabet(void *param);
void taskLED(void *param);

void app_main(void) {
    xTaskCreate(taskAlphabet, "Task Alphabet", 1024, NULL, 3, NULL);
    xTaskCreate(taskLED, "Task LED", 1024, NULL, 3, NULL);
}

void taskAlphabet(void *param){
    while(1){
        for(x=0; x<10; x++){
            for(y=x; y<26 ; y++){
                printf(alphabet[y]);
            }
            for(y=0; y<x ; y++){
                printf(alphabet[y]);
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");
        vTaskDelay(1000);
    }
    vTaskDelete(NULL);
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

