#include <Adafruit_MotorShield.h>
#include <Servo.h>

#ifndef MOTORS
#define MOTORS
class Motors {
	public: 
		void setup();
		void run_left(float speed);
		void run_right(float speed);
		void move_servo(int position);
		void stop_motors();

	private:
		Adafruit_MotorShield shield;
		Adafruit_DCMotor *left_motor;
		Adafruit_DCMotor *right_motor;
		Servo servo;
};
#endif
