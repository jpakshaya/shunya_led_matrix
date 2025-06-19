#include "MAP_COLOR.h"
#include "led_strip.h"


void MAP_COLOR(int index, char color){
    
    switch(color){

        case 'R':
        led_strip_set_pixel(led_strip, index, 255, 0, 0);
        break;

        case 'G':
        led_strip_set_pixel(led_strip, index, 0, 255, 0);
        break;

        case 'B':
        led_strip_set_pixel(led_strip, index, 0, 0, 255);
        break;

        case 'W':
        led_strip_set_pixel(led_strip, index, 255, 255, 255);
        break;
        
    }
}



