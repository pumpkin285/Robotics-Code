//tasks for the conveyor during auton
#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"

int ringmode;
double conveyorvelocity;
void autonTasks::ring()
{
  while(true)
  {
    switch(ringmode)
    {
      case 1: //stop
      conveyor.stop();
      break;
      case 2: //intake
      conveyor.spin(fwd, conveyorvelocity, pct);
      break;
      default:
      wait(10, msec);
      break;
    }
    wait(5, msec);
  }
}