#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"

int driveexit;

void autonTasks::collectring(double distance, int direction1, bool conveyoroff, double time)
{
  //collect rings while driving
  goal = distance;
  direction = direction1;
  drivemode = 2;
  ringmode = 2;
  wait(time, sec);
  drivemode = 1;
  if(conveyoroff)
  {
    ringmode = 1;
  }
}

void autonTasks::calibrate()
{
  in.calibrate();
  while(in.isCalibrating())
  {
    wait(10, msec);
  }
}

void autonTasks::drivefwd(double distance, int direction1, double time)
{
  //just drive fwd or backwards
  goal = distance;
  direction = direction1;
  drivemode = 2;
  wait(time, sec);
  drivemode = 1;
}

void autonTasks::drivehold(double distance, int direction1, double error, double time)
{
  //for holding onto middle mogos in case a tug of war happens
  goal = distance;
  direction = direction1;
  drivemode = 2;
  wait(time, sec);
  driveexit = 0;
  while(driveexit == 0)
  {
    driveexit = 1;
    for(int i = 0; i < drivedelay; i++)
    {
      if(fabs(lefterror[i]) >= error || fabs(righterror[i]) >= error )
      {
        driveexit = 0;
      }
    }
  }
  drivemode = 1;
}

void autonTasks::turn(double degrees, int direction1, double time)
{
  //turn to global heading
  goal = degrees;
  direction = direction1;
  drivemode = 3;
  wait(time, sec);
  drivemode = 1;
}

void autonTasks::drivelift(double distance, int direction1, double fbdeg, double fbtime, double time)
{
  //drive, then lift after "fbtime" seconds
  goal = distance;
  direction = direction1;
  fbtarget = fbdeg;
  drivemode = 2;
  wait(fbtime, sec);
  if(fbtarget >= fb.position(deg))
  {
    fbmode = 2;
  }
  else
  {
    fbmode = 3;
  }
  wait(time - fbtime, sec);
  drivemode = 1;
}

void autonTasks::turnlift(double degrees, int direction1, double fbdeg, double fbtime, double time)
{
  //turn, then lift after "fbtime" seconds
  goal = degrees;
  direction = direction1;
  fbtarget = fbdeg;
  drivemode = 3;
  wait(fbtime, sec);
  if(fbtarget >= fb.position(deg))
  {
    fbmode = 2;
  }
  else
  {
    fbmode = 3;
  }
  wait(time - fbtime, sec);
  //fbmode = 1;
  drivemode = 1;
}

void autonTasks::driveback(double distance, int direction1, double backtime, double time)
{
  //drive, then lower back lift after "backtime" seconds
  goal = distance;
  direction = direction1;
  drivemode = 2;
  wait(backtime, sec);
  backmode = 3;
  wait(time - backtime, sec);
}
void autonTasks::backclamp()
{
  backmode = 4;
  wait(0.12, sec);
}

void autonTasks::backrelease()
{
  backmode = 3;
  wait(0.31, sec);
}

void autonTasks::frontclamp()
{
  fcmode = 2;
  wait(0.05, sec);
}

void autonTasks::frontrelease()
{
  fcmode = 1;
  wait(0.05, sec);
}

void autonTasks::lift(double degrees, double waittime, bool waitfb)
{
  //lift to a certain position, then see if "waitfb" would wait for it to finish
  if(fb.position(deg) < degrees)
  {
    fbmode = 2;
    fbtarget = degrees;
  }
  else 
  {
    fbmode = 3;
    fbtarget = degrees;
  }
  wait(waittime, sec);
  if(waitfb)
  {
    while(fbmode != 1)
    {
      wait(10, msec);
    }
  }
}