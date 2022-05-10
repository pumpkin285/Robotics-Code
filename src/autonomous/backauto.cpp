//file for back claw subsystem during autonomous

#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"

int backmode;
void autoTask::back()
{
  while(true)
  {
    switch(backmode)
    {
      case 1: //default
      bc.set(false);
      backlift.set(true);
      break;
      case 2: //clamp
      bc.set(true);
      wait(0.1, sec);
      backlift.set(false);
      break;
      case 3: //release
      backlift.set(true);
      wait(0.2, sec);
      bc.set(false);
      break;
      default:
      wait(10, msec);
      break;
    }
    wait(10, msec);
  }
}