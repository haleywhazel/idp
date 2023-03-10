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
  return;
}

int follow_line()
{
  const int line_sensor_readings = line_sensor();

  switch (line_sensor_readings)
  {
    case 0://0000
      move_forwards();
      break;
    case 4://0100
      move_forwards(INCREASED_MOTOR_SPEED, DEFAULT_MOTOR_SPEED);
      break;
    case 2://0010
      move_forwards(DEFAULT_MOTOR_SPEED, INCREASED_MOTOR_SPEED);
      break;
    case 15://1111
      return 1;
    case 3://0011
      return 2;
  }
  
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
