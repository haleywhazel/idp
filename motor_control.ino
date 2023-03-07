#include "motor_control.h"

int follow_wall_left_motor_speed(float distance_difference, float gyroscope_value) {
	return max(min((default_motor_speed + (distance_difference * proportional_constant)) * 255, 255), 0);
}

int follow_wall_right_motor_speed(float distance_difference, float gyroscope_value) {
	// return max(min((default_motor_speed - (distance_difference * proportional_constant)) * 255, 255), 0);
	return default_motor_speed * 255;
}

MotorSpeeds follow_wall_motor_speeds(int current_wall) {
	// TODO: obtain values from functions used in sensor.h
	const float side_distance = distance_right();
	const float gyroscope_value;
	const float distance_difference = side_distance - desired_side_distances[current_wall];

	if(distance_difference > difference_tolerance) {
		Serial.print("over tolerance\n");
	}

	const int left_motor = follow_wall_left_motor_speed(distance_difference, gyroscope_value);
	const int right_motor = follow_wall_right_motor_speed(distance_difference, gyroscope_value);

	String msg = String("side distance: " + String(side_distance, DEC) + " | LM " + String(left_motor, DEC) + " | RM " + String(right_motor, DEC) + "\n");
	Serial.print(msg);
	return MotorSpeeds { left_motor, right_motor };
}

void normal_orientation(unsigned long t, int current_wall) {
	unsigned long t0 = millis();
	const long dt = 100;

	float front_distance = distance_front();
	float side_distance = distance_right();

	LM->setSpeed(default_motor_speed);
	RM->setSpeed(default_motor_speed);
	LM->run(FORWARD);
	RM->run(FORWARD);

	int i;
	while (millis() < t0 + t && front_distance >= 200) {
		if (millis() >= t0 + (i * dt)) {
			float fd = distance_front();
			float sd = distance_right();

			float delta_front = fd - front_distance;
			float delta_side = sd - side_distance;

			float distance_desired = desired_side_distances[current_wall] - sd;
			if (sd < 0 && distance_desired > 0) {

			}
		}
	}
}

void follow_wall(int current_wall) {
    const MotorSpeeds motor_speeds = follow_wall_motor_speeds(current_wall);

	LM->setSpeed(abs(motor_speeds.left_motor));
	RM->setSpeed(abs(motor_speeds.right_motor));

	if (motor_speeds.left_motor >= 0)
		LM->run(FORWARD);
	else
		LM->run(BACKWARD);
	if (motor_speeds.right_motor >= 0)
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

void move_forwards(int duration) {
	LM->setSpeed(default_motor_speed);
	RM->setSpeed(default_motor_speed);
	LM->run(FORWARD);
	RM->run(FORWARD);
	delay(duration);
	stop_motors();
}