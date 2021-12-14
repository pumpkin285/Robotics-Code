#include "vex.h"
#include "math.h"
#include "../../include/definitions/tasks.h"

double start, end;
void autoTasks::drivereset()
{
  fl.resetPosition();
  fr.resetPosition();
  bl.resetPosition();
  br.resetPosition();
}

double autoTasks::motorpower(double currenterror, double previouserror, float kP, float kD)
{
  float pterm = currenterror * kP;
  float dterm = (currenterror - previouserror) * kD;
  float power = pterm + dterm;
  return power;
}

double autoTasks::min(double value1, double value2, double value3)
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

void autoTasks::drivestop()
{
  fl.stop();
  fr.stop();
  bl.stop();
  br.stop();
}

void autoTasks::calibrate()
{
  in.calibrate();
  while(in.isCalibrating())
  {
    wait(10, msec);
  }
}

void autoTasks::backmogomove(double speed, double todegree)
{ 
  if(todegree < bml.position(deg))
  {
    while(bml.position(deg) > todegree)
    {
      bml.spin(reverse, speed, pct);
      bmr.spin(reverse, speed, pct);
    }
    bml.stop();
    bmr.stop();
  }
  else
  {
     while(bml.position(deg) < todegree)
    {
      bml.spin(fwd, speed, pct);
      bmr.spin(fwd, speed, pct);
    }
    bml.stop();
    bmr.stop();
  }
}

void autoTasks::fourbarmove(double speed, double todegree)
{ 
  if(todegree < fb.position(deg))
  {
    while(fb.position(deg) > todegree)
    {
      fb.spin(reverse, speed, pct);
    }
    fb.stop();
  }
  else
  {
     while(fb.position(deg) < todegree)
    {
      fb.spin(fwd, speed, pct);
    }
    fb.stop();
  }
}

void autoTasks::frontclawmove(bool frontclaw, double time)
{
  fc.set(frontclaw);
  wait(time, sec);
}

void autoTasks::backclawmove(bool backclaw, double time)
{
  bc.set(backclaw);
  wait(time, sec);
}

void autoTasks::backmogobutton(double speed)
{
  while(!bm.pressing())
  {
    bml.spin(fwd, speed, pct);
    bmr.spin(fwd, speed, pct);
    wait(10, msec);
  }
  bml.stop();
  bmr.stop();
}

void autoTasks::mogoreset(double frontdeg, double backdeg)
{
  while(fb.position(deg) > frontdeg || bml.position(deg) > backdeg)
  {
    if(fb.position(deg) > frontdeg)
    {
      fb.spin(reverse, 100, pct);
    }
    else
    {
      fb.stop();
    }
    if(bml.position(deg) > backdeg)
    {
      bml.spin(reverse, 100, pct);
      bmr.spin(reverse, 100, pct);
    }
    else
    {
      bml.stop();
      bmr.stop();
    }
  }
  bml.stop();
  bmr.stop();
  fb.stop();
}