//tasks for the back lift and back mogo 
#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"

int backmode;
void autonTasks::back()
{
  while(true)
  {
    switch(backmode)
    {
      case 1: //claw down position to take mogo
      backlift.set(false);
      bc.set(false);
      break;
      case 2: //claw up position to be inside 18
      backlift.set(true);
      bc.set(true);
      case 3: //release mogo
      backlift.set(false);
      wait(0.3, sec);
      bc.set(false);
      break;
      case 4: //clamp mogo
      bc.set(true);
      wait(0.1, sec);
      backlift.set(true);
      break;
      case 5: //lower mogo position
      bc.set(false);
      backlift.set(true);
      default:
      wait(10, msec);
      break;
      
    }
    wait(5, msec);
  }
}