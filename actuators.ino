#include "actuators.h"

void actuators_setup()
{
  AFMS.begin();
  //servo.attach(SERVO);
}

void wait_for_button_press()
{
 while (digitalRead(BUTTON_PIN) == LOW)
    delay(TIME_DELAY);
 while (digitalRead(BUTTON_PIN) == HIGH)
    delay(TIME_DELAY);
}

void move_forwards(int LM_speed = DEFAULT_MOTOR_SPEED, int RM_speed = DEFAULT_MOTOR_SPEED)
{
  digitalWrite(ASTABLE_PIN, HIGH);
  LM->setSpeed(LM_speed);
  RM->setSpeed(RM_speed);
  LM->run(FORWARD);
  RM->run(FORWARD);
}

void move_backwards(int LM_speed = DEFAULT_MOTOR_SPEED, int RM_speed = DEFAULT_MOTOR_SPEED)
{
  digitalWrite(ASTABLE_PIN, HIGH);
  LM->setSpeed(LM_speed);
  RM->setSpeed(RM_speed);
  LM->run(BACKWARD);
  RM->run(BACKWARD);
}

void adjust_left()
{
  digitalWrite(ASTABLE_PIN, HIGH);
  LM->setSpeed(DEFAULT_MOTOR_SPEED - MOTOR_SPEED_DIFFERENCE);
  RM->setSpeed(DEFAULT_MOTOR_SPEED);
  LM->run(FORWARD);
  RM->run(FORWARD);
}

void adjust_right()
{
  digitalWrite(ASTABLE_PIN, HIGH);
  LM->setSpeed(DEFAULT_MOTOR_SPEED);
  RM->setSpeed(DEFAULT_MOTOR_SPEED - MOTOR_SPEED_DIFFERENCE);
  LM->run(FORWARD);
  RM->run(FORWARD);
}

void turn_left()
{
  digitalWrite(ASTABLE_PIN, HIGH);
  LM->setSpeed(DEFAULT_MOTOR_SPEED - MOTOR_SPEED_DIFFERENCE);
  RM->setSpeed(DEFAULT_MOTOR_SPEED);
  LM->run(FORWARD);
  RM->run(FORWARD);
}

void turn_right()
{
  LM->setSpeed(DEFAULT_MOTOR_SPEED);
  RM->setSpeed(DEFAULT_MOTOR_SPEED);
  LM->run(FORWARD);
  RM->run(BACKWARD);
}

void stop_motors()
{
  digitalWrite(ASTABLE_PIN, LOW);
  LM->run(RELEASE);
  RM->run(RELEASE);
}

void grabber_up()
{
  return;
}

void grabber_down()
{
  return;
}
