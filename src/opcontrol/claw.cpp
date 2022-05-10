//file for front claw and back claw + lift during driver control

#include "vex.h"
#include "robot-config.h"
#include "definitions/opcontrol.h"
bool r1, r2, a, b, y, rarrow;

//function for front claw control
void driveTask::frontmogo(bool frontclaw, bool frontrelease)
{
  if(frontclaw == true && frontrelease == false)
  {
    fc.set(true);
  }
  else if(frontclaw == false && frontrelease == true)
  {
    fc.set(false);
  }
}

//function for back claw control
void driveTask::backmogo(bool backclaw, bool backrelease, bool endrelease, bool liftback)
{
  if(backclaw == true && backrelease == false && endrelease == false && liftback == false)
  {
    bc.set(true);
    wait(0.1, sec); //short delay for the back claw to hook onto the mogo before lifting up
    backlift.set(false);
  }
  else if(backclaw == false && backrelease == true && endrelease == false && liftback == false)
  {
    backlift.set(true);
    wait(0.2, sec); //delay for back lift to go down before releasing the mogo
    bc.set(false);
  }
  else if(backclaw == false && backrelease == false && endrelease == true && liftback == false)
  {
    backlift.set(true);
  }
  else if(backclaw == false && backrelease == false && endrelease == false && liftback == true)
  {
    backlift.set(false);
  }
}

//thread for front and back mogo subsystems
void driveTask::clawthread()
{
  while(true)
  {
    r1 = Controller1.ButtonR1.pressing();
    r2 = Controller1.ButtonR2.pressing();
    a = Controller1.ButtonA.pressing();
    b = Controller1.ButtonB.pressing();
    y = Controller1.ButtonY.pressing();
    
    rarrow = Controller1.ButtonRight.pressing();
    frontmogo(r1, r2);
    backmogo(a, b, y, rarrow);
    wait(10, msec);
  }
}