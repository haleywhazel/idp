#include <Adafruit_MotorShield.h>
#include <Servo.h>

#include "constants.h"
#include "sensors.h"

void move_forwards(int LM_speed, int RM_speed);

void move_backwards(int LM_speed, int RM_speed);

void stop_motors();

// Turn left for a certain duration
void turn_left();

// Turn right for a certain duration
void turn_right();

void move_from_start();

// Returns: 0, normal; 1, grab block; 2, place protocol
int follow_line();

// Returns: true, grabbed; false, not grabbed
bool grab_block();

// Places block
void place_block();
