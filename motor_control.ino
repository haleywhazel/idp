#include "motor_control.h"

void Motors::setup() {
	//Adafruit_MotorShield shield = Adafruit_MotorShield();
	shield.begin();
	// Adafruit_DCMotor *left_motor = shield.getMotor(lm); // Adjust based on actual port connected
	// Adafruit_DCMotor *right_motor = shield.getMotor(rm); // Adjust based on actual port connected
	Servo servo;
	servo.attach(servo_sig);
}

void Motors::run_left(float speed) {
	Adafruit_DCMotor *m = shield.getMotor(lm);
	m->setSpeed(max(abs(speed), 1) * 255);
	m->run(speed > 0 ? FORWARD : BACKWARD);
}

void Motors::run_right(float speed) {
	Adafruit_DCMotor *m = shield.getMotor(rm);
	m->setSpeed(max(abs(speed), 1) * 255);
	m->run(speed > 0 ? FORWARD : BACKWARD);
}

void Motors::stop_motors() {
	Adafruit_DCMotor *m1 = shield.getMotor(rm);
	Adafruit_DCMotor *m2 = shield.getMotor(lm);
	m1->run(RELEASE);
	m2->run(RELEASE);
}

void Motors::move_servo(int position) {
	servo.write(position);
}