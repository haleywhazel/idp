#include "robot.h"

void Robot::setup() {
    Serial.begin(9600);
    Sensors s;
    s.setup();
    Motors m;
    m.setup();

    MotorSpeeds ms;
    ms.left_motor = 0;
    ms.right_motor = 0;

    Orientation o;
    o.distance_from_front = 0;
    o.distance_from_side = 0;
    o.angle_from_side = 0;

    sensors = s;
    motors = m;
    current_wall = start;
    current_speed = ms;
    orientation = o;

    while (digitalRead(button) == HIGH) {
        delay(5);
    }
}

void Robot::update_orientation() {
    float uf = sensors.front_ultrasonic();
    float ir1_cm = sensors.read_ir(ir_1);
    float ir2_cm = sensors.read_ir(ir_2);

    float theta = atan((ir2_cm - ir1_cm) / ir_offset);
    float sd = ir1_cm * cos(theta);
    float fd = uf * cos(theta);

    Serial.println(theta);

    Orientation o;
    o.angle_from_side = (theta * ema_k) + (orientation.angle_from_side * (1 - ema_k));
    o.distance_from_front = fd;
    o.distance_from_side = (sd * ema_k) + (orientation.distance_from_side * (1 - ema_k));
    
    orientation = o;
}

Orientation Robot::desired_orientation() {
    Orientation o;
    o.angle_from_side = 0;
    o.distance_from_front = 0;

    switch (current_wall) {
        case start:
            o.distance_from_side = 40;
            break;
        case ramp:
            o.distance_from_side = 40;
            break;
        case blocks:
            o.distance_from_side = 40;
            break;
        case tunnel:
            o.distance_from_side = 40;
            break;
    }

    return o;
}

void Robot::set_speed() {
    Orientation desired = desired_orientation();

    float delta_side = desired.distance_from_side - orientation.distance_from_side;
    float delta_theta = desired.angle_from_side - orientation.angle_from_side;

    float rms = (proportional_k * delta_side) + default_speed;
    float lms = default_speed;

    motors.run_right(rms);
    motors.run_left(lms);

    MotorSpeeds ms;
    ms.left_motor = lms;
    ms.right_motor = rms;

    current_speed = ms;
}