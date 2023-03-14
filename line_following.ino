#include "line_following.h"

void move_from_start()
{
  move_forwards();
  wait_until_all_sensors_have_detected_line();
  delay(500);
  wait_until_all_sensors_have_detected_line();
  delay(500);

  /*
  turn_right();
  wait_until_line_sensor_on(3);
  wait_until_line_sensor_on(2);
  wait_until_line_sensor_on(1);*/

  turn_left();
  wait_until_line_sensor_on(0);
  wait_until_line_sensor_on(1);
  wait_until_line_sensor_on(2);


/*  move_forwards();
  delay(200);

  stop_motors();
  delay(2000);*/
}

int follow_line()
{  
  const int line_sensor_input = line_sensor_sum();

  if (line_sensor_input == 2)
    adjust_right();
  else if (line_sensor_input == 4)
    adjust_left();
  else if (line_sensor_input == 12)
  {
    return 1;
  }
  else if (line_sensor_input == 3)
  {
    return 2;
  }
  else
    move_forwards();
  
  return 0;
}

bool grab_block()
{
  turn_left();

  wait_until_line_sensor_sum_is(0);//0000
  wait_until_line_sensor_sum_is(15);//1111
  
  move_forwards();

  delay(1000);
  // check for block and grab

  move_backwards();

  wait_until_line_sensor_sum_is(15);//1111

  turn_right();
  
  wait_until_line_sensor_sum_is(0);//0000
  wait_until_line_sensor_sum_is(12);//1100

  move_forwards();
  
  wait_until_line_sensor_sum_is(0);//0000

  return true;
}

void place_block()
{
  turn_right();
  
  wait_until_line_sensor_sum_is(0);//0000
  wait_until_line_sensor_sum_is(15);//1111

  move_forwards();
  delay(1000);
  // place block

  move_backwards();
  
  wait_until_line_sensor_sum_is(15);//1111

  turn_left();
  
  wait_until_line_sensor_sum_is(0);//0000
  wait_until_line_sensor_sum_is(3);//0011

  move_forwards();
  
  wait_until_line_sensor_sum_is(0);//0000
}

void skip_junction()
{
  stop_motors();
  delay(1000);
  move_forwards();
  delay(100);
}
