//tasks for the front claw and four bar lift in auton
#include "vex.h"
#include "robot-config.h"
#include "math.h"
#include "definitions/autonomous.h"

double fbtarget, fbvelocity;
int fbmode, fcmode;
void autonTasks::front()
{
  while(true)
  {
    switch(fbmode)
    {
      case 1: //stop
      fb.stop();
      break;
      case 2: //goes up 
      while(fb.position(deg) < fbtarget)
      {
        fb.spin(fwd, fbvelocity, pct);
        wait(10, msec);
      }
      fbmode = 1;
      break;
      case 3: //goes down
      while(fb.position(deg) > fbtarget)
      {
        fb.spin(reverse, fbvelocity, pct);
        wait(10, msec);
      }
      fbmode = 1;
      default: 
      wait(10, msec);
      break;
    }
    switch(fcmode)
    {
      case 1: //release
      fc.set(false);
      break;
      case 2: //clamp
      fc.set(true);
      break;
      default: 
      wait(10,msec);
      break;
    }
    wait(5, msec);
  }
}