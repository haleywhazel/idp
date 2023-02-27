#include "motor_control.h"

int adjusted_left_motor_speed(float distance_difference, float gyroscope_value) {
	int adjustment = static_cast<int>(distance_difference * distance_proportional_control_constant);
	adjustment += static_cast<int>(gyroscope_value * gyroscope_control_constant);
	return default_motor_speed + adjustment;
}

int adjusted_right_motor_speed(int turning, float gyroscope_value) {
	int adjustment = static_cast<int>(gyroscope_value * gyroscope_control_constant);
	adjustment += turning_constant * turning;
	return default_motor_speed;
}

std::pair<int, int> adjusted_motor_speeds(int current_wall, int turning) {
	// TODO: obtain values from functions used in sensor.h
	const float side_distance = distance_right();
	const float gyroscope_value;
	const float distance_difference = side_distance - desired_side_distances[current_wall];

	const int left_motor = adjusted_left_motor_speed(distance_difference, gyroscope_value);
	const int right_motor = adjusted_right_motor_speed(turning, gyroscope_value);

	return std::make_pair(left_motor, right_motor);
}