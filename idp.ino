#include "line_following.h"
#include "sensors.h"

void setup() {
  sensors_setup();
  move_from_start();
}

void loop() {
  // State Variable
  // 0 - main following loop, 1 - turning to grab block, 2 - placing block
  int state = 0;
}
