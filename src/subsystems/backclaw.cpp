#include "vex.h"
#include "../include/definitions/tasks.h"
#include "robot-config.h"

int clicknumber = 0;
bool currentx = false;
bool previousx = false;

void driverTasks::setbackclaw()
{
  if(currentx == true && previousx == false)
  {
    clicknumber++;
  }
  if(clicknumber % 2 == 0)
  {
    bc.set(false);
  }
  else
  {
    bc.set(true);
  }
  previousx = currentx;
  currentx = Controller1.ButtonX.pressing();
}
