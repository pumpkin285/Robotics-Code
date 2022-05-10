//file for different autonomous functions used 

#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"
#include "definitions/init.h"

void autoTask::drivestop()
{
  fl.stop();
  ml.stop();
  bl.stop();
  fr.stop();
  mr.stop();
  br.stop();
}

double startx, starty, goalx, goaly, goalheading, goaldistance, xheading, yheading, reducedbearing, fullbearing, inertialbearing, goalheading1;
int adjustrotation;
double autoTask::calcheading(double startx, double starty, double endx, double endy)
{
  goaldistance = sqrt(pow(endx - startx, 2) + pow(endy - starty, 2));
  yheading = endy - starty;
  xheading = endx - startx;
  reducedbearing = fabs(asin(yheading / goaldistance));
  if(yheading >= 0 && xheading >= 0)
  {
    fullbearing = reducedbearing * 180 / M_PI;
  }
  else if(yheading >= 0 && xheading < 0)
  {
    fullbearing = 180 - reducedbearing * 180 / M_PI;
  }
  else if(yheading < 0 && xheading < 0)
  {
    fullbearing = 180 + reducedbearing * 180 / M_PI;
  }
  else 
  {
    fullbearing = 360 - reducedbearing * 180 / M_PI;
  }
  inertialbearing = 90 - fullbearing;
  adjustrotation = -floor((inertialbearing - headingdeg + 180) / 360);
  goalheading1 = inertialbearing + adjustrotation * 360;
  return goalheading1 / 180 * M_PI;
}

bool loopexit;
void autoTask::turntopoint(double endx, double endy, double time)
{
  goalx = endx;
  goaly = endy;
  drivemode = 2;
  wait(50, msec);
  
  
  while(loopexit == false && timecount < time)
  {
    //currenttime = Brain.Timer.time(sec);
    loopexit = true;
    timecount = currenttime - starttime;
    
    for(int i = 0; i < turndelay; i++)
    {
      if(fabs(headingerror[i]) > turnerror)
      {
        loopexit = false;
      }
    }
    wait(50, msec);
  }
  drivemode = 1;
}

void autoTask::turn(double goal1, double time)
{
  goalheading = goal1;
  drivemode = 9;
  wait(time, sec);
  drivemode = 1;
}

void autoTask::startlift(double liftgoal, bool finish)
{
  fbgoal = liftgoal;
  fbmode = 2;
  if(finish)
  {
    while(fbmode != 1)
    {
      wait(10, msec);
    }
  }
}
void autoTask::drivefwdtime(double distance, double time)
{
  goal = distance;
  drivemode = 4;
  wait(time, sec);
  drivemode = 1;
}

void autoTask::doubleturn(double distance, double time)
{
  goalheading = distance;
  drivemode = 10;
  wait(time, sec);
  drivemode = 1;
}
void autoTask::drivefwd(double distance, double time)
{
  goal = distance;
  drivemode = 4;
  while(loopexit == false && timecount < time)
  { 
    //currenttime = Brain.Timer.time(sec);
    loopexit = true;
    timecount = currenttime - starttime;
    
    for(int i = 0; i < turndelay; i++)
    {
      if(fabs(lefterror[i]) > driveerror)
      {
        loopexit = false;
      }
    }
    wait(50, msec);
  }
  drivemode = 1;
}
double autoTask::motorpower(double currenterror, double previouserror, float kP, float kD)
{
  float pterm = currenterror * kP;
  float dterm = (previouserror - currenterror) * kD;
  float power = pterm + dterm;
  return power;
}

double autoTask::min(double value1, double value2, double value3)
{
  if(value1 < value2 && value1 < value3)
  {
    return value1;
  }
  else if(value2 < value3)
  {
    return value2;
  }
  else
  {
    return value3;
  }
}