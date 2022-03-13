#include "vex.h"
#include "../include/definitions/tasks.h"
#include "robot-config.h"

double backmogolimit = -500;
double backmogoposition;
bool backmogohit;
void driverTasks::backmogo(bool backup, bool backdown)
{
  backmogoposition = (bml.position(deg) + bmr.position(deg)) / 2;
  backmogohit = bm.pressing();
  if(backup == true && backdown == false && backmogohit == false)
  {
    bml.spin(fwd, 80, pct);
    bmr.spin(fwd, 80, pct);
  }
  else if (backup == false && backdown == true)
  {
    bml.spin(reverse, 80, pct);
    bmr.spin(reverse, 80, pct);
  }
  else
  {
    bml.stop();
    bmr.stop();
  }
}