//this file includes the thread for the back mogo claw

#include "vex.h"
#include "robot-config.h"
#include "../../include/definitions/opcontrol.h"

bool r1, r2, a, b, y;
int mogoloop;

void driverTasks::mogo(bool backup, bool backdown, bool frontup, bool frontdown, bool backrelease)
{
  //condition for back claw
  if(backup == false && backdown == true && backrelease == false)
  {
    backlift.set(false);
    wait(0.3, sec);
    bc.set(false);
  }
  else if(backup == true && backdown == false && backrelease == false)
  {
    bc.set(true);
    wait(0.1, sec);
    backlift.set(true);
  }
  else if(backup == false && backdown == false && backrelease == true)
  {
    backlift.set(false);
    bc.set(true);
  }
  //condition for front claw
  if(frontup == true && frontdown == false)
  {
    fc.set(false);
  }
  else if(frontup == false && frontdown == true)
  {
    fc.set(true);
  }
}

void driverTasks::back()
{
  //thread for front and back mogo claw
  while(true)
  {
    r1 = Controller1.ButtonR1.pressing();
    r2 = Controller1.ButtonR2.pressing();
    a = Controller1.ButtonA.pressing();
    b = Controller1.ButtonB.pressing();
    y = Controller1.ButtonY.pressing();
    mogo(a, b, r2, r1, y);
    wait(10, msec);
    mogoloop ++;
  }
}