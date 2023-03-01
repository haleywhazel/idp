#include "wrapper.h"

int current_wall = 0;

void initial_setup() {
    Serial.begin(9600);
    sensors_setup();
    move_forwards(1000);
    turn_right();
}

void main_loop() {
    while (distance_front < turning_distances[current_wall]) {
        follow_wall(current_wall);
        delay(50);
        // ADD ANY ADDITIONAL STUFF THE ROBOT NEEDS TO DO HERE (eg turn to pickup or drop block)
        switch (current_wall) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }
    }
    turn_left();
    stop_motors();
    //current_wall++;
}