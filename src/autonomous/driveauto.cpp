//file for thread of the drive during auton

#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"
#include "definitions/init.h"
#include "math.h"
double starttime, currenttime, timecount;
double setpointdeg, startenc, endenc;
int drivemode, loopnumber;

void autoTask::driving()
{
  while(true)
  {
    wait(10, msec);
    switch(drivemode) 
    {
      case 1: //stop
      drivestop();
      break;
      case 2: //set values for gyroturn
      loopnumber = 0;
      accel = 10;
      starttime = Brain.Timer.time(sec);
      timecount = 0;
      startx = currentx;
      starty = currenty;
      loopexit = false;
      goalheading = calcheading(startx, starty, goalx, goaly);
      if(goalheading > headingdeg)
      {
        directionconst = 1;
      }
      else 
      {
        directionconst = -1;
      }
      for(int i = 0; i < turndelay; i++)
      {
        headingerror[i] = goalheading - heading;
      }
      drivemode = 3;
      break;
      case 3: //turn
      gyroturn();
      break;
      case 4: //set value for drive
      setpointdeg = goal / (2.75 * M_PI / 360);
      startenc = -ytrack.position(deg);
      endenc = startenc + setpointdeg;
      loopnumber = 0;
      
      
      starttime = Brain.Timer.time(sec);
      
      timecount = 0;
      loopexit = false;
      if(goal > 0)
      {
        directionconst = 1;
        accel = 10;
      }
      else 
      {
        directionconst = -1;
        accel = 2;
      }
      for(int i = 0; i < drivedelay; i++)
      {
        lefterror[i] = setpointdeg;
      }
      drivemode = 5;
      
      break;
      case 5: //drive
      drive();
      break;
      case 6: //cubic bezier set lookahead points
      t = 0;
      ringmode = 2;
      pure::cpathgen();
      loopnumber = 0;
      drivemode = 7;
      accel = 7;
      if(fabs(calcheading(startx, starty, q1x, q1y) - heading) < 90)
      {
        directionconst = 1;
      }
      else 
      {
        directionconst = -1;
      }
      break;
      case 7: //cubic bezier pathing
      pure::bezpathfollow();
      break;
      case 8: //quadratic bezier set lookahead points
      t = 0;
      pure::qpathgen();      
      loopnumber = 0;
      drivemode = 7;
      accel = 7;
      if(fabs(calcheading(startx, starty, c1x, c1y) - heading) < 90)
      {
        directionconst = 1;
      }
      else 
      {
        directionconst = -1;
      }
      break;
      case 9: //just turn to a certain heading
      loopnumber = 0;
      accel = 10;
      starttime = Brain.Timer.time(sec);
      timecount = 0;
      startx = currentx;
      starty = currenty;
      loopexit = false;
      if(goalheading > headingdeg)
      {
        directionconst = 1;
      }
      else 
      {
        directionconst = -1;
      }
      for(int i = 0; i < turndelay; i++)
      {
        headingerror[i] = goalheading - headingdeg;
      }
      drivemode = 3;
      break;
      case 10: //two mogo turn
      loopnumber = 0;
      accel = 10;
      starttime = Brain.Timer.time(sec);
      timecount = 0;
      startx = currentx;
      starty = currenty;
      loopexit = false;
      if(goalheading > headingdeg)
      {
        directionconst = 1;
      }
      else 
      {
        directionconst = -1;
      }
      for(int i = 0; i < turndelay; i++)
      {
        headingerror[i] = goalheading - headingdeg;
      }
      drivemode = 11;
      
      break;
      case 11:
      twomogoturn();
      break;

      default: 
      wait(10, msec);
      break;  
    }
    if(drivemode == 6)
    {
      Brain.Screen.setCursor(8, 1);
      Brain.Screen.print(1);
    }
  }
}