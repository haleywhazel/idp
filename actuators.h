#include "constants.h"

void actuators_setup();

void wait_for_button_press();

void move_forwards(int LM_speed = DEFAULT_MOTOR_SPEED, int RM_speed = DEFAULT_MOTOR_SPEED);

void move_backwards(int LM_speed = DEFAULT_MOTOR_SPEED, int RM_speed = DEFAULT_MOTOR_SPEED);

void stop_motors();

void adjust_left();

void adjust_right();

void grabber_up();

void grabber_down();
