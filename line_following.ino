#include "line_following.h"

void move_forwards(int LM_speed = DEFAULT_MOTOR_SPEED, int RM_speed = DEFAULT_MOTOR_SPEED)
{
  LM->setSpeed(LM_speed);
  RM->setSpeed(RM_speed);
  LM->run(FORWARD);
  RM->run(FORWARD);
}

void move_backwards(int LM_speed = DEFAULT_MOTOR_SPEED, int RM_speed = DEFAULT_MOTOR_SPEED)
{
  LM->setSpeed(LM_speed);
  RM->setSpeed(RM_speed);
  LM->run(BACKWARD);
  RM->run(BACKWARD);
}

void adjust_left()
{
  LM->setSpeed(DECREASED_MOTOR_SPEED / 2);
  RM->setSpeed(DECREASED_MOTOR_SPEED);
  LM->run(FORWARD);
  RM->run(FORWARD);
}

void adjust_right()
{
  LM->setSpeed(DECREASED_MOTOR_SPEED);
  RM->setSpeed(DECREASED_MOTOR_SPEED / 2);
  LM->run(FORWARD);
  RM->run(FORWARD);
}

void turn_left()
{
  LM->setSpeed(DEFAULT_MOTOR_SPEED);
  RM->setSpeed(DEFAULT_MOTOR_SPEED);
  LM->run(BACKWARD);
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
	LM->run(RELEASE);
	RM->run(RELEASE);
}

void move_from_start()
{
  move_forwards();
  wait_until_line_sensor_is(15);//1111
  delay(200);
  wait_until_line_sensor_is(15);//1111

  turn_right();

  
  while (digitalRead(LINE_SENSOR_PINS[2]) || digitalRead(LINE_SENSOR_PINS[3]))
    delay(LINE_FOLLOWING_TIME_DELAY);

  delay(500);

  move_forwards();
  delay(100);

  
  //wait_until_line_sensor_is(3);//0011
  
  //wait_until_line_sensor_is(0);//0000

}

int follow_line()
{
  int readings[4];
  
  for (int i = 0; i < 4; ++i)
    readings[i] = line_sensor_readings(i);

  if (readings[1] == 1) //xx1x
    adjust_right();
  else if (readings[2] == 1) //x1xx
    adjust_left();
  else
    move_forwards();
  
  return 0;
}

bool grab_block()
{
  turn_left();

  wait_until_line_sensor_is(0);//0000
  wait_until_line_sensor_is(15);//1111
  
  move_forwards();

  delay(1000);
  // check for block and grab

  move_backwards();

  wait_until_line_sensor_is(15);//1111

  turn_right();
  
  wait_until_line_sensor_is(0);//0000
  wait_until_line_sensor_is(12);//1100

  move_forwards();
  
  wait_until_line_sensor_is(0);//0000

  return true;
}

void place_block()
{
  turn_right();
  
  wait_until_line_sensor_is(0);//0000
  wait_until_line_sensor_is(15);//1111

  move_forwards();
  delay(1000);
  // place block

  move_backwards();
  
  wait_until_line_sensor_is(15);//1111

  turn_left();
  
  wait_until_line_sensor_is(0);//0000
  wait_until_line_sensor_is(3);//0011

  move_forwards();
  
  wait_until_line_sensor_is(0);//0000
}

void skip_junction()
{
  move_forwards();
  wait_until_line_sensor_is(0);//0000
}
