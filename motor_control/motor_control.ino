#include "motor_control.h"

int follow_wall_left_motor_speed(float distance_difference, float gyroscope_value) {
	int adjustment = static_cast<int>(distance_difference * distance_proportional_control_constant);
	adjustment += static_cast<int>(gyroscope_value * gyroscope_control_constant);
	return default_motor_speed + adjustment;
}

int follow_wall_right_motor_speed(float gyroscope_value) {
	return default_motor_speed + static_cast<int>(gyroscope_value * gyroscope_control_constant);
}

std::pair<int, int> follow_wall_motor_speeds(int current_wall) {
	// TODO: obtain values from functions used in sensor.h
	const float side_distance = distance_right();
	const float gyroscope_value;
	const float distance_difference = side_distance - desired_side_distances[current_wall];

	const int left_motor = follow_wall_left_motor_speed(distance_difference, gyroscope_value);
	const int right_motor = follow_wall_right_motor_speed(gyroscope_value);

	return std::make_pair(left_motor, right_motor);
}

void follow_wall(int current_wall) {
    const std::pair<int, int> motor_speeds = follow_wall_motor_speeds(current_wall);
	LM->setSpeed(abs(motor_speeds.first));
	RM->setSpeed(abs(motor_speeds.second));
	if (motor_speeds.first >= 0)
		LM->run(FORWARD);
	else
		LM->run(BACKWARD);
	if (motor_speeds.second >= 0)
		RM->run(FORWARD);
	else
		RM->run(BACKWARD);
}

void stop_motors() {
	LM->run(RELEASE);
	RM->run(RELEASE);
}

void turn_left() {
	LM->setSpeed(default_motor_speed);
	RM->setSpeed(default_motor_speed);
	LM->run(BACKWARD);
	RM->run(FORWARD);
	delay(turning_duration);
	stop_motors();
}

void turn_right() {
	LM->setSpeed(default_motor_speed);
	RM->setSpeed(default_motor_speed);
	LM->run(FORWARD);
	RM->run(BACKWARD);
	delay(turning_duration);
	stop_motors();
}