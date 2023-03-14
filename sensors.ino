#include "sensors.h"

void sensors_setup()
{
	for (int pin : LINE_SENSOR_PINS)
		pinMode(pin, INPUT);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(VCC, OUTPUT);
  digitalWrite(VCC, HIGH);
  pinMode(ASTABLE_PIN, OUTPUT);
  
	pinMode(ULTRASOUND_TRIG_PIN, OUTPUT);
	pinMode(ULTRASOUND_ECHO_PIN, INPUT);

	pinMode(BLUE_SENSOR_PIN, INPUT);
  pinMode(BROWN_SENSOR_PIN, INPUT);

	pinMode(VCC, OUTPUT);
	digitalWrite(VCC, HIGH);
  digitalWrite(ASTABLE_PIN, LOW);
}

bool is_block_blue()
{
  return digitalRead(BLUE_SENSOR_PIN);
}

bool is_block_brown()
{
  return digitalRead(BROWN_SENSOR_PIN);
}

int line_sensor(int i)
{
  return digitalRead(LINE_SENSOR_PINS[i]);
}

int line_sensor_sum()
{
	return line_sensor(0) * 1 +
	       line_sensor(1) * 2 +
	       line_sensor(2) * 4 +
	       line_sensor(3) * 8;
}

void wait_until_line_sensor_on(int i)
{
  while (line_sensor(i) != 1)
      delay(TIME_DELAY);
}

void wait_until_line_sensor_sum_is(int value)
{
  while (line_sensor_sum() != value)
    delay(TIME_DELAY);
}

void wait_until_all_sensors_have_detected_line()
{
  bool detected[4] = {false};
  int sum = 0;
  while (sum < 3)
  {
    for (int i = 0; i < 4; ++i)
    {
      if (line_sensor(i) && !detected[i])
      {
        detected[i] = true;
        ++sum;
      }
    }
    delay(TIME_DELAY);
  }
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
