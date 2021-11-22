#include "vex.h"
#include "../include/definitions/tasks.h"
#include "robot-config.h"

void driverTasks::setbrake()
{
    if(Controller1.ButtonA.pressing())
    {
      fl.setStopping(hold);
      fr.setStopping(hold);
      bl.setStopping(hold);
      br.setStopping(hold);
    }
    else if(Controller1.ButtonB.pressing())
    {
      fl.setStopping(coast);
      fr.setStopping(coast);
      bl.setStopping(coast);
      br.setStopping(coast);
    }
  
}