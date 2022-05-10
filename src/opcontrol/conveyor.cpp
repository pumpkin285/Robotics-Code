//file for conveyor in driver control

#include "vex.h"
#include "definitions/opcontrol.h"
#include "robot-config.h"

bool previousup, currentup, l1, l2;
int conveyorno;

//function for controlling conveyor motor
void driveTask::ring(bool up, bool down)
{
  //count how many times the button for conveyor up is pressed
  previousup = currentup;
  currentup = up;
  if(!previousup && currentup)
  {
    conveyorno += 1;
  }
  //case for conveyor
  if(conveyorno % 2 == 1 && !down)
  {
    conveyor.spin(fwd, 127, pct);
  }
  else if(conveyorno %2 == 0 && down)
  {
    conveyor.spin(reverse, 127, pct);
  }
  else
  {
    conveyor.stop();
  }
}

//thread for conveyor subsystem
void driveTask::ringthread()
{
  while(true)
  {
    l1 = Controller1.ButtonL1.pressing();
    l2 = Controller1.ButtonL2.pressing();
    ring(l1, l2);
    wait(10, msec);
  }
}
    
