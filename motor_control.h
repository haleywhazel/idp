#include <Adafruit_MotorShield.h>
#include "sensors.h"

// Constant values - adjust for calibration
const int default_motor_speed;
const float[4] desired_side_distances;
const float[4] turning_distances;
const float gyroscope_control_constant;
const float distance_proportional_control_constant;
const int turning_constant;

// Setup motor
Adafruit_motorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *LM = AFMS.getMotor(2); // Adjust based on actual port connected
Adafruit_DCMotor *RM = AFMS.getMotor(1); // Adjust based on actual port connected

// Returns the adjusted left motor speed based on sensor readings to keep a certain
// desired side distance to the wall, increasing if the robot is too far away and
// decreasing if the robot is too close.
// Arguments:
//     float side_distance   : current distance to the side wall
//     float gyroscope_value : gyroscope value obtained from built in Arduino sensor
// Output:
//     int                   : required left motor speed
int adjusted_left_motor_speed(float side_distance, float gyroscope_value);

// Returns the adjusted right motor speed based on sensor readings. If the robot
// should turn, an additional adjustment is added.
// Arguments:
//     int turning           : 1 = turning left, 0 = not turning, -1 = turning right
//     float gyroscope_value : gyroscope value obtained from built in Arduino sensor
// Output:
//     int                   : required right motor speed
int adjusted_right_motor_speed(int turning, float gyroscope_value, int current_wall);

// Obtains sensor readings using methods in sensor.h and returns an std::pair of
// required left and right motor values.
// Arguments:
//     int current_wall      : current wall based on decided label values
//     int turning           : 1 = turning left, 0 = not turning, -1 = turning right
// Output:
//     std::pair<int, int>   : motor speeds, pair.first = left, pair.second = right
std::pair<int, int> adjusted_motor_speeds(int current_wall, int turning);

// Set current motor speeds.
// Arguments:
//     int current_wall      : current wall based on decided label values
//     int turning           : 1 = turning left, 0 = not turning, -1 = turning right
// Output:
//     None
void set_motors(int current_wall, int turning);