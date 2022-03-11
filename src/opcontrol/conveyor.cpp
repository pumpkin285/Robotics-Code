//this file includes the thread for the conveyor

#include "vex.h"
#include "robot-config.h"
#include "../../include/definitions/opcontrol.h"

bool currentl1, previousl1, l2;
int conveyorno;

void driverTasks::rings(bool currentintake, bool previousintake, bool outtake)
{
  if(currentintake == true && previousintake == false)
  {
    conveyorno += 1;
  }
  if(conveyorno % 2 == 1 && outtake == false)
  {
    conveyor.spin(fwd, 100, pct);
  }
  else if(conveyorno % 2 == 0 && outtake == true)
  {
    conveyor.spin(reverse, 100, pct);
  }
  else
  {
    conveyor.stop();
  }
}

void driverTasks::ring()
{
  while(true)
  {
    previousl1 = currentl1;
    currentl1 = Controller1.ButtonL1.pressing();
    l2 = Controller1.ButtonL2.pressing();
    rings(previousl1, currentl1, l2);
    wait(10, msec);
  }
}