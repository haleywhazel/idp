#include "sensors.h"

void sensors_setup()
{
  /*
	pinMode(front_ultrasound_trig, OUTPUT);
	pinMode(right_ultrasound_trig, OUTPUT);
	pinMode(front_ultrasound_echo, INPUT);
	pinMode(right_ultrasound_echo, INPUT);
	pinMode(ultrasonic_vcc, OUTPUT);
	pinMode(button_in, INPUT);
	pinMode(button_vcc, OUTPUT);*/

	//digitalWrite(button_vcc, HIGH);
	//digitalWrite(ultrasonic_vcc, HIGH);
}

bool is_block_blue()
{
  return true;
}

int line_sensor()
{
  return 0;
}

void wait_until_line_sensor_is(int value)
{
  while (line_sensor() != value)
    delay(LINE_FOLLOWING_TIME_DELAY);
}
/*
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
	const float measured_distance = static_cast<float>(duration) / 5.8;
	if (front) {
		if (measured_distance >= 0.0)
			current_front_distance = measured_distance;
		return current_front_distance;
	}
	else {
		if (measured_distance >= 0.0)
			current_side_distance = measured_distance;
		return current_side_distance;
	}
}

float distance_front() {
	return distance_from_ultrasound(true);
}

float distance_right() {
	return distance_from_ultrasound(false);
}*/
