#include "wrapper.h"

#ifndef CURRENT_WALL
#define CURRENT_WALL
int current_wall = 0;
#endif

void initial_setup() {
    Serial.begin(9600);
    sensors_setup();
    AFMS.begin();
    // move_forwards(1000);
    // turn_right();
}

void main_loop() {
    unsigned long t0 = millis();
    while (millis() < t0 + 10000) { 
      delay(100);
    }
    while (millis() < t0 + 30000) {
        follow_wall(current_wall);
        delay(500);
        // // ADD ANY ADDITIONAL STUFF THE ROBOT NEEDS TO DO HERE (eg turn to pickup or drop block)
        // switch (current_wall) {
        //     case 0:
        //         break;
        //     case 1:
        //         break;
        //     case 2:
        //         break;
        //     case 3:
        //         break;
        // }
    }
    Serial.print("stopping");
    stop_motors();
    while(true) {
        delay(1000);
    }
    // turn_left();
    // stop_motors();
    //current_wall++;
}