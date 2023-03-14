#include <Adafruit_MotorShield.h>
#include <Servo.h>

#ifndef ROBOT_VARS
#define ROBOT_VARS
const int DEFAULT_MOTOR_SPEED = 250;
const int MOTOR_SPEED_DIFFERENCE = 230;
const int TIME_DELAY = 25;

const int BUTTON_PIN = 12;
const int BLUE_SENSOR_PIN = 10;
const int BROWN_SENSOR_PIN = 8;
const int LM_PIN = 4;
const int RM_PIN = 3;
const int SERVO_PIN = 9;
const int LINE_SENSOR_PINS[4] = {7, 6, 5, 4};
const int VCC = 13;
const int ASTABLE_PIN = 11;
const int ULTRASOUND_TRIG_PIN = 2;
const int ULTRASOUND_ECHO_PIN = 3;


Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *LM = AFMS.getMotor(LM_PIN);
Adafruit_DCMotor *RM = AFMS.getMotor(RM_PIN);
Servo SERVO;

int state = 0;
bool grabbed = false;
#endif
