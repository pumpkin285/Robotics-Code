#include "vex.h"
#include "../include/definitions/tasks.h"
#include "robot-config.h"


double fourbarlimit = 600;
double fourbarposition;
void driverTasks::frontmogo(double fourbar, bool clawdown, bool clawup)
{
  fourbarposition = fb.position(deg);
  if(fourbarposition < fourbarlimit && fourbar > 0)
  {
    fb.spin(fwd, fourbar, pct);
  }
  else if(0 < fourbarposition && fourbar < 0)
  {
    fb.spin(fwd, fourbar, pct);
  }
  else
  {
    fb.stop();
  }
  if(clawup == true && clawdown == false)
  {
    fc.set(false);
  }
  else if (clawup == false && clawdown == true)
  {
    fc.set(true);
  }
}