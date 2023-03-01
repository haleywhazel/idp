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
    }
    turn_left();
    current_wall++;
}