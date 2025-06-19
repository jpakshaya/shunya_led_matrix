#include "MAP_LED.h"
#include "MAP_COLOR.h"

void MAP_LED(int index, char character, int frame, int part) {

    switch(character) {

        case '0':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'R');
            }
            break;

        case '1':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case '2':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case '3':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'R');
            }
            break;

        case '4':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case '5':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case '6':
            if(frame == 1) {
                MAP_COLOR(index, 'B');
            } else {
                MAP_COLOR(index, 'R');
            }
            break;

        case '7':
            if(frame == 1) {
                MAP_COLOR(index, 'B');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case '8':
            if(frame == 1) {
                MAP_COLOR(index, 'B');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case '9':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'R');
            }
            break;

        case 'A':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'B':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'C':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'R');
            }
            break;

        case 'D':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'E':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'F':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'R');
            }
            break;

        case 'G':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'H':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'I':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'J':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'K':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'L':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'M':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'N':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'O':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'P':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'Q':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'R':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'S':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'T':
            if(frame == 1) {
                MAP_COLOR(index, 'R');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'U':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;

        case 'V':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'W':
            if(frame == 1) {
                MAP_COLOR(index, 'G');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'X':
            if(frame == 1) {
                MAP_COLOR(index, 'B');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'Y':
            if(frame == 1) {
                MAP_COLOR(index, 'B');
            } else {
                MAP_COLOR(index, 'B');
            }
            break;

        case 'Z':
            if(frame == 1) {
                MAP_COLOR(index, 'B');
            } else {
                MAP_COLOR(index, 'G');
            }
            break;
    }
}
