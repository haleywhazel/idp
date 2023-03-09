#include "motor_control.h"

void Motors::setup() {
	Adafruit_MotorShield shield = Adafruit_MotorShield();
	shield.begin();
	Adafruit_DCMotor *left_motor = shield.getMotor(lm); // Adjust based on actual port connected
	Adafruit_DCMotor *right_motor = shield.getMotor(rm); // Adjust based on actual port connected
	Servo servo;
	servo.attach(servo_sig);
}

void Motors::run_left(float speed) {
	uint8_t s = max(abs(speed), 1) * 255;
	left_motor->setSpeed(s);
	left_motor->run(speed > 0 ? FORWARD : BACKWARD);
}

void Motors::run_right(float speed) {
	uint8_t s = max(abs(speed), 1) * 255;
	right_motor->setSpeed(s);
	right_motor->run(speed > 0 ? FORWARD : BACKWARD);
}

void Motors::stop_motors() {
	left_motor->run(RELEASE);
	right_motor->run(RELEASE);
}

void Motors::move_servo(int position) {
	servo.write(position);
}