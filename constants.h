#include <Adafruit_MotorShield.h>
#include <Servo.h>

#ifndef ROBOT_VARS
#define ROBOT_VARS
const int LM_PIN;
const int RM_PIN;
const int SERVO_PIN = 9;
const int DEFAULT_MOTOR_SPEED = 150;
const int INCREASED_MOTOR_SPEED = 180;
const int LINE_FOLLOWING_TIME_DELAY = 50;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *LM = AFMS.getMotor(LM_PIN);
Adafruit_DCMotor *RM = AFMS.getMotor(RM_PIN);
Servo SERVO;
#endif
