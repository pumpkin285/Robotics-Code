//file for four bar lift during driver control

#include "vex.h"
#include "robot-config.h"
#include "definitions/opcontrol.h"

//set limit for four bar, to not damage motors
double fbuplimit = 700;
double fbdownlimit = 50;

double fbposition, righty;

//function for four bar control
void driveTask::fourbar(double fbvelocity)
{
  if(fbvelocity > 0)
  {
    if(fbposition < fbuplimit)
    {
      fb.spin(fwd, fbvelocity, pct);
    }
    else
    {
      fb.stop();
    }
  }
  else if(fbvelocity < 0)
  {
    if(fbposition > fbdownlimit)
    {
      fb.spin(fwd, fbvelocity, pct);
    }
    else
    {
      fb.spin(fwd, fbvelocity, pct);
    }
  }
  else
  {
    fb.stop();
  }
}

//thread for four bar subsystem
void driveTask::fourbarthread()
{
  while(true)
  {
    fbposition = fb.position(deg);
    righty = Controller1.Axis2.value();
    fourbar(righty);
    wait(10, msec);
  }
}