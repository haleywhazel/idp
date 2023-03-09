#include "robot.h"

Robot robot;

void setup() {
    robot.setup();
}

void loop() {
    Serial.print("starting robot\n");
    unsigned long t0 = millis();
    int l = 0;
    unsigned long turning_duration = 1000;
    // while (millis() < t0 + turning_duration) {
    //     robot.motors.run_right(-default_speed);
    //     robot.motors.run_left(default_speed);
    // }
    // robot.motors.stop_motors();

    robot.update_orientation();
    Serial.println(robot.orientation.distance_from_front);
    while(millis() < t0 + 10000) {
        robot.update_orientation();
        Serial.print(String("side distance: " + String(robot.orientation.distance_from_side) + " | front distance: " + String(robot.orientation.distance_from_front) + " | angle from side: " + String(robot.orientation.angle_from_side) + "\n"));
        robot.set_speed();
        Serial.print(String("motor speeds: " + String(robot.current_speed.left_motor) + " | " + String(robot.current_speed.right_motor) + "\n"));
    }

    // while (millis() < t0 + turning_duration) {
    //     robot.motors.run_right(default_speed);
    //     robot.motors.run_left(-default_speed);
    // }
    // robot.motors.stop_motors();

    // while(robot.orientation.distance_from_front >= 200) {
    //     robot.update_orientation();
    //     Serial.print(String("side distance: " + String(robot.orientation.distance_from_side) + " | front distance: " + String(robot.orientation.distance_from_front) + " | angle from side: " + String(robot.orientation.angle_from_side) + "\n"));
    //     robot.set_speed();
    //     Serial.print(String("motor speeds: " + String(robot.current_speed.left_motor) + " | " + String(robot.current_speed.right_motor) + "\n"));
    // }

    robot.motors.stop_motors();
    while(true) { delay(1000); }
}