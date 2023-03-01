#include "sensors.h"

void sensors_setup() {
	// pinMode(front_ultrasound_trig, OUTPUT);
	pinMode(right_ultrasound_trig, OUTPUT);
	// pinMode(front_ultrasound_echo, INPUT);
	pinMode(right_ultrasound_echo, INPUT);
}

float convert_ultrasound_sensor(float input) {
	return input;
}

// bool is_block_blue() {
// 	float input; // TODO: obtain from sensors
// 	return input > colour_reading_threshold;
// }

float distance_from_ultrasound(bool front) {
	int trig;
	int echo;
	if (front) {
		trig = front_ultrasound_trig;
		echo = front_ultrasound_echo;
	}
	else {
		trig = right_ultrasound_trig;
		echo = right_ultrasound_echo;
	}
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	const int duration = pulseIn(echo, HIGH);
	return static_cast<float>(duration) / 5.8;
}

float distance_front() {
	return distance_from_ultrasound(true);
}

float distance_right() {
	return distance_from_ultrasound(false);
}


/*
INCLUDE FOLLOWING AS NEEDED

float convert_80cm_distance_sensor(float input, bool far = false) {
	float output;
	return output;
}

float convert_150cm_distance_sensor(float input, bool far = false) {
	float output;
	return output;
}
*/