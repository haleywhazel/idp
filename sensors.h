#include "constants.h"

void sensors_setup();

bool is_block_blue();

//float distance_from_ultrasound(bool front);

// 0000: 0
// 0100: 4
// 0010: 2
// 1100: 12
// 0011: 3
// 1000: 8
// 1111: 15
int line_sensor_sum();

int line_sensor(int i);

void wait_until_line_sensor_on(int i);

void wait_until_line_sensor_sum_is(int value);

void wait_until_all_sensors_have_detected_line();
