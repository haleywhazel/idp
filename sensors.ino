#include "sensors.h"

void sensors_setup()
{
	for (int pin : LINE_SENSOR_PINS)
		pinMode(pin, INPUT);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC, HIGH);
  pinMode(ASTABLE_PIN, OUTPUT);
  
  /*
	pinMode(front_ultrasound_trig, OUTPUT);
	pinMode(right_ultrasound_trig, OUTPUT);
	pinMode(front_ultrasound_echo, INPUT);
	pinMode(right_ultrasound_echo, INPUT);
	pinMode(ultrasonic_vcc, OUTPUT);

	pinMode(COLOUR_SENSOR_PIN, INPUT);
  pinMode(BROWN_SENSOR_PIN, INPUT);
	//pinMode(BUTTON_PIN, HIGH);

	pinMode(VCC, OUTPUT);
	digitalWrite(VCC, HIGH);*/

	//digitalWrite(button_vcc, HIGH);
	//digitalWrite(ultrasonic_vcc, HIGH);
}

void wait_for_button_press()
{
	while (digitalRead(BUTTON_PIN) == HIGH)
		delay(TIME_DELAY);
}

bool is_block_blue()
{
  return digitalRead(COLOUR_SENSOR_PIN);
}

int line_sensor()
{
	return digitalRead(LINE_SENSOR_PINS[0]) * 1 +
	       digitalRead(LINE_SENSOR_PINS[1]) * 2 +
	       digitalRead(LINE_SENSOR_PINS[2]) * 4 +
	       digitalRead(LINE_SENSOR_PINS[3]) * 8;
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
