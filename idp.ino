#include "line_following.h"
#include "sensors.h"

void setup() {
  sensors_setup();
  wait_for_button_press();
  move_from_start();
}

void loop() {
  // State Variable
  // 0 - main following loop, 1 - turning to grab block, 2 - placing block
  while (state == 0)
    state = follow_line();

  /*

  if (state = 1)
  {
    if (!grabbed)
      grabbed = grab_block();
    else
      skip_junction();
    state = 0;
  }
  else if (state = 2)
  {
    if (grabbed)
    {
      place_block();
      grabbed = false;
    }
    else
      skip_junction();
    state = 0;
  }
  
  
  */
}
