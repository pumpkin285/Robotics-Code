//file for front claw and four bar subsystems during autonomous

#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"

int fbmode, fcmode;
double fbgoal, fbvelocity;

//thread for four bar
void autoTask::fourbar()
{
  while(true)
  {
    switch(fbmode)
    {
      case 1: //four bar stop
      fb.stop();
      break;
      case 2: //determines whether four bar goes up or down
      if(fb.position(deg) < fbgoal)
      {
        fbmode = 3;
      }
      else 
      {
        fbmode = 4;
      }
      break;
      case 3: //four bar goes up
      if(fb.position(deg) < fbgoal)
      {
        fb.spin(fwd, fbvelocity, pct);
      }
      else
      {
        fbmode = 1; //move to stop, ended action
      }
      break;
      case 4: //four bar goes down
      if(fb.position(deg) > fbgoal)
      {
        fb.spin(reverse, fbvelocity, pct);
      }
      else
      {
        fbmode = 1; 
      }
      break;
      default:
      wait(10, msec);
      break;
    }
    wait(10, msec);
  }
}

//thread for front claw
void autoTask::frontclaw()
{
  while(true)
  {
    switch(fcmode)
    {
      case 1: //front claw release
      fc.set(false);
      break;
      case 2: //front claw clamp
      fc.set(true);
      break;
      default:
      wait(10, msec);
      break;

    }
    wait(10, msec);
  }
}