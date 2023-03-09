#include "sensors.h"
#include "motor_control.h"
#include "pinout.h"

#ifndef ROBOT
#define ROBOT

enum Wall { start = 0, ramp = 1, blocks = 2, tunnel = 3 };

struct MotorSpeeds {
	float left_motor;
	float right_motor;
};

struct Orientation {
    float distance_from_side;
    float angle_from_side;
    float distance_from_front;
};

class Robot {
    public:
        Orientation orientation;
        Wall current_wall;
        Sensors sensors;
        void setup();
        void update_orientation();
        void set_speed();
        MotorSpeeds current_speed;
        Motors motors;

    private:
        // Sensors sensors;
        // Motors motors;
        //MotorSpeeds current_speed;
        Orientation desired_orientation();
};

#endif