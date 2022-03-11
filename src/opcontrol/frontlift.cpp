//this file for the front mogo thread, for the four bar and the front claw

#include "vex.h"
#include "robot-config.h"
#include "../../include/definitions/opcontrol.h"

double fbposition;
double fblimit = 650;
double righty;

void driverTasks::frontlift(double fourbar)
{
  if(fbposition < fblimit && fourbar > 0)
  {
    fb.spin(fwd, fourbar, pct);
  }
  else if(fbposition > -10 && fourbar < 0) // don't go down too far
  {
    fb.spin(fwd, fourbar, pct);
  }
  else
  {
    fb.stop();
  }
  //had to separate conditions, so that the four bar does not get stuck in out-of boundary situations
  
}

void driverTasks::front()
{
  //thread for front mobile goal
  while(true)
  {
    righty = Controller1.Axis2.value();
    fbposition = fb.position(deg);
    frontlift(righty);
    wait(10, msec);
  }
}