#include "robot.h"

Robot robot;

void setup() {
    robot.setup();
}

void loop() {
    Serial.print("starting robot\n");
    unsigned long t0 = millis();
    int l = 0;
    while(millis() <= t0 + 30000) {
        unsigned long t = millis();
        robot.update_orientation();
        Serial.print(String("side distance: " + String(robot.orientation.distance_from_side) + " | front distance: " + String(robot.orientation.distance_from_front) + " | angle from side: " + String(robot.orientation.angle_from_side) + "\n"));
        // if (t >= (l * 250) + t0) {
        //     l++;
        //     robot.set_speed();
        // }
        //Serial.print(String("side distance: " + String(robot.orientation.distance_from_side) + " | front distance: " + String(robot.orientation.distance_from_front) + " | angle from side: " + String(robot.orientation.angle_from_side) + "\n"));
        // Serial.print(String("motor speeds: " + String(robot.current_speed.left_motor) + " | " + String(robot.current_speed.right_motor) + "\n"));
    }
    while(true) { delay(1000); }
}