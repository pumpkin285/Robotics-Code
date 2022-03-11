//tasks for the drive during auton
#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"

int drivemode;

void autonTasks::driving()
{
  while(true)
  {
    switch(drivemode)
    {
      case 1: //stop
      drivestop();
      break;
      case 2: //drive set values, then move to case where drive pid is done
      setpointdeg = goal / 1.2 / (4 * M_PI / 360);
      drivereset();
      switch(direction)
      /*
      1 = forward
      2 = backward
      */
      {
        case 1:
        directionconst = 1;
        accel = 5;
        break;
        case 2:
        directionconst = -1;
        accel = 5;
        break;
        default:
        directionconst = 0;
        accel = 0;
        break;
      }
      for(int i = 0; i < drivedelay; i++)
      {
        lefterror[i] = (-1) * setpointdeg;
        righterror[i] = (-1) * setpointdeg;
      }
      loopnumber = 1;
      drivemode = 4;
      break;
      case 3: //turn set values, then move to where turn pid is done
      //setpoint is always a positive number
      previousheading = in.rotation(deg);
      currentheading = in.rotation(deg);
      loopnumber = 0;
      accel = 10;
      starttime = Brain.Timer.time(msec);
      timecount = 0;
      switch(direction)
      /*
      1 = right/clockwise
      2 = left/counter-clockwise
      */
      {
      case 1:
      directionconst = 1;
      break;
      case 2:
      directionconst = -1;
      break;
      default:
      directionconst = 0;
      break;
      }
      for(int i = 0; i < turndelay; i++)
      {
        headingerror[i] = goal;
      }
      drivemode = 5;
      break;
      case 4: //drive pid
      drive();
      break;
      case 5: //turn pid
      gyroturn();
      break;
      default:
      wait(10, msec);
      break;
    }
    wait(5, msec);
  }
}