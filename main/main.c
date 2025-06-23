#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include <string.h>
#include "led_strip.h"
#include "driver/rmt_tx.h"
#include "driver/rmt_rx.h"

#include "MAP_LED.h"



//UART 
#define UART_PORT UART_NUM_1
#define TX_PIN GPIO_NUM_17
#define RX_PIN GPIO_NUM_16
#define BAUD_RATE 115200
#define BUFFER_SIZE 1024

//LED
#define RMT_LED_STRIP_CHANNEL RMT_CHANNEL_0
#define RMT_GPIO 18
#define MATRIX_WIDTH 8
#define MATRIX_HEIGHT 8
#define LED_COUNT (MATRIX_WIDTH * MATRIX_HEIGHT)


led_strip_handle_t led_strip;



void app_main(void)
{

 //UART PART 

    //UART configiration
    uart_config_t uart_config= {
        .baud_rate= BAUD_RATE,
        .data_bits= UART_DATA_8_BITS,
        .parity= UART_PARITY_DISABLE,
        .stop_bits= UART_STOP_BITS_1,
        .flow_ctrl= UART_HW_FLOWCTRL_DISABLE
    };

    uart_driver_install(UART_PORT,BUFFER_SIZE*2,0,0,NULL,0);
    uart_param_config(UART_PORT,&uart_config);
    uart_set_pin(UART_PORT, TX_PIN, RX_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    const char *MSG1= "HELLO\n";
    const char *MSG2= "READY\n";

    uart_write_bytes(UART_PORT, MSG1, strlen(MSG1));
    printf("Sent: %s",MSG1);

    uint8_t data1[BUFFER_SIZE];
    uint8_t data2[BUFFER_SIZE];
    int len1= uart_read_bytes(UART_PORT,data1,BUFFER_SIZE-1, pdMS_TO_TICKS(2000));
    
    
    if(len1>0){
        if(data1[len1-1]=='\n'){
            data1[len1-1]= '\0';
            printf("Msg received: %s",(char*)data1);
            uart_write_bytes(UART_PORT,MSG2,strlen(MSG2));
            printf("Sent: %s",MSG2);
            int len2= uart_read_bytes(UART_PORT,data2,BUFFER_SIZE-1, pdMS_TO_TICKS(2000));
            if(len2>0){
               if(data2[len2-1]=='\n'){
               data2[len2-1]= '\0';
               printf("Msg received: %s",(char*)data2);    //SO WE HAVE THE PASSWORD IN DATA2
               }
            }
        }
    }

    vTaskDelay(pdMS_TO_TICKS(1000));



 //LED MATRIX PART
    
    // LED strip configuration
    led_strip_config_t strip_config = {
        .strip_gpio_num = RMT_GPIO,
        .max_leds = LED_COUNT,
        .led_model = LED_MODEL_WS2812,
        .flags.invert_out = false,   //dont invert, 0 is LOW 1 is HIGH
    };

    // RMT configuration
    led_strip_rmt_config_t rmt_config = {
        .clk_src = RMT_CLK_SRC_DEFAULT,
        .resolution_hz = 10 * 1000 * 1000, // 0.1 microsecond
        //.mem_block_symbols = 64,   //can send msg to 2 LEDs at a time (24*2=48 bits)
        //.trans_queue_depth = 4,    //THIS IS NOT AVALIABLE IN OLDER VERSION OF ESP, CHECK ONCE
        .flags.with_dma = false,    //dont use direct memory access (keep it simple for cpu)
    };

    // Initialize LED strip
    led_strip_new_rmt_device(&strip_config, &rmt_config, &led_strip); 
    led_strip_clear(led_strip);

    char color; //color
    int i;


    //publishing colors on LED matrix
    int frame=1;
    int part=1;  //first half or second half of LED matrix
   for (int i = 0; data2[i] != '\0'; i++) {
    for (int frame = 1; frame <= 2; frame++) {
        for (int y = 0; y < MATRIX_HEIGHT; y++) {
            for (int x = 0; x < MATRIX_WIDTH; x++) {
                int index = y * MATRIX_WIDTH + x;

                if (y < 3) {
                    // Top 7 rows = part 1
                    MAP_LED(index, data2[i], frame, 1);
                } else if (y > 4) {
                    // Bottom 7 rows = part 2
                    MAP_LED(index, data2[i], frame, 2);
                }
            }
        }

        led_strip_refresh(led_strip);  // Show frame
        vTaskDelay(pdMS_TO_TICKS(1000));


        led_strip_clear(led_strip);
        led_strip_refresh(led_strip);
        vTaskDelay(pdMS_TO_TICKS(1000)); // Delay between frames
    }
}

}    
