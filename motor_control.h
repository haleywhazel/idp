#include <Adafruit_MotorShield.h>
#include "sensors.h"

// Constant values - adjust for calibration
const int default_motor_speed;
const float[4] desired_side_distances = { 50, 50, 50, 50 };
const float[4] turning_distances = { 100, 100, 100, 100 };
const float gyroscope_control_constant = 0;
const float distance_proportional_control_constant = 0;
const int turning_duration = 1000;

// Setup motor
Adafruit_motorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *LM = AFMS.getMotor(2); // Adjust based on actual port connected
Adafruit_DCMotor *RM = AFMS.getMotor(1); // Adjust based on actual port connected

// Returns the adjusted left motor speed based on sensor readings to keep a certain
// desired side distance to the wall, increasing if the robot is too far away and
// decreasing if the robot is too close.
// Arguments:
//     float distance_difference : distance difference to side wall
//     float gyroscope_value     : gyroscope value obtained from built in Arduino sensor
// Output:
//     int                   : required left motor speed
int follow_wall_left_motor_speed(float distance_difference, float gyroscope_value);

// Returns the adjusted right motor speed based on sensor readings. If the robot
// should turn, an additional adjustment is added.
// Arguments:
//     float gyroscope_value    : gyroscope value obtained from built in Arduino sensor
// Output:
//     int                      : required right motor speed
int follow_wall_right_motor_speed(float gyroscope_value);

// Obtains sensor readings using methods in sensor.h and returns an std::pair of
// required left and right motor values.
// Arguments:
//     int current_wall         : current wall based on decided label values
// Output:
//     std::pair<int, int>   : motor speeds, pair.first = left, pair.second = right
std::pair<int, int> follow_wall_motor_speeds(int current_wall);

// Set current motor speeds based on wall to follow
// Arguments:
//     int current_wall      : current wall based on decided label values
// Output:
//     None
void follow_wall(int current_wall);

// Stop current motors.
void stop_motors();

// Turn left for a certain duration
void turn_left();

// Turn right for a certain duration
void turn_right();

// Move forwards for a certain duration
// Arguments:
//     int duration          : duration to move forwards (milliseconds)
// Output:
//     NOne
void move_forwards(int duration);