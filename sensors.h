
#ifndef SENSOR_CONSTS
#define SENSOR_CONSTS
const float colour_reading_threshold;
const int front_ultrasound_trig = 4;
const int front_ultrasound_echo = 5;
const int right_ultrasound_trig = 6;
const int right_ultrasound_echo = 2;
const int ultrasonic_vcc = 3;
const int button_in = 12;
const int button_vcc = 13;
#endif

// Sensors setup - run in void setup() to set parameters for the sensors
void sensors_setup();

// Convert readings from the colour sensor and determine whether it is blue or brown
// Arguments:
//     None
// Output:
//     bool        : blue = true, brown = false
bool is_block_blue();

// Obtain front distance reading from front ultrasound sensor
// Arguments:
//     bool front  : front or side sensor (true = front)
// Output:
//     float       : distance reading in millimetres
float distance_from_ultrasound(bool front);

// Obtain front distance reading from front ultrasound sensor (wrapper)
// Arguments:
//     None
// Output:
//     float       : distance reading in millimetres
float distance_front();

// Obtain side distance reading from right ultrasound sensor (wrapper)
// Arguments:
//     None
// Output:
//     float       : distance reading in millimetres
float distance_right();


/*
INCLUDE FOLLOWING AS NEEDED
// Convert readings from the 80cm distance sensor to an expected distance value based
// on measured readings.
// Arguments:
//     float input : sensor reading input
//     bool far    : in the cases where two values are possible, whether or not to 
//                   return the farther value (default false, returns closer value)
// Output:
//     float       : current distance value
float convert_80cm_distance_sensor(float input, bool far);

// Convert readings from the 150cm distance sensor to an expected distance value
// based on measured readings.
// Arguments:
//     float input : sensor reading input
//     bool far    : in the cases where two values are possible, whether or not to 
//                   return the farther value (default false, returns closer value)
// Output:
//     float       : current distance value
float convert_150cm_distance_sensor(float input, bool far);
*/