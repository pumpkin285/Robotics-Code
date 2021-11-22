#include "vex.h"
#include "../include/definitions/tasks.h"
#include "robot-config.h"

double forward1, turning;
double rightx, righty;
int l1, l2;
bool r1, r2, a, b;

void driverTasks::driving()
{
  forward1 = Controller1.Axis3.position();
  turning = Controller1.Axis4.position();
  a = Controller1.ButtonA.pressing();
  b = Controller1.ButtonB.pressing();
  chassis(forward1, turning, a, b);
}

void driverTasks::front()
{
  righty = Controller1.Axis2.position();
  r1 = Controller1.ButtonR1.pressing();
  r2 = Controller1.ButtonR2.pressing();
  frontmogo(righty, r1, r2);
}

void driverTasks::back()
{
  l1 = Controller1.ButtonL1.pressing();
  l2 = Controller1.ButtonL2.pressing();
  backmogo(l1, l2);
}