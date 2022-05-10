//file for chassis during driver control

#include "vex.h"
#include "robot-config.h"
#include "definitions/opcontrol.h"
using namespace vex;

double actualturn, leftpower, rightpower, speedconst;
double lefty, leftx;
bool currenthold, previoushold, currentslow, previousslow, x, uarrow;
int holdno, slowno;

//function for drive motors control
void driveTask::drive(double forward, double turn)
{
  actualturn = 0.85 * turn;
  leftpower = forward + actualturn;
  rightpower = forward - actualturn;
  fl.spin(fwd, speedconst * leftpower, pct);
  ml.spin(fwd, speedconst * leftpower, pct);
  bl.spin(fwd, speedconst * leftpower, pct);
  fr.spin(fwd, speedconst * rightpower, pct);
  mr.spin(fwd, speedconst * rightpower, pct);
  br.spin(fwd, speedconst * rightpower, pct);
}

//function for stop hold on platform
void driveTask::stophold(bool hold)
{
  //count how many times the hold button is pressed
  previoushold = currenthold;
  currenthold = hold;
  if(!previoushold && currenthold)
  {
    holdno++;
  }
  //default as coast
  if(holdno % 2 == 0)
  {
    fl.setStopping(brakeType::coast);
    ml.setStopping(brakeType::coast);
    bl.setStopping(brakeType::coast);
    fr.setStopping(brakeType::coast);
    mr.setStopping(brakeType::coast);
    br.setStopping(brakeType::coast);
  }
  //changes to hold after pressing button once
  else
  {
    fl.setStopping(brakeType::hold);
    ml.setStopping(brakeType::hold);
    bl.setStopping(brakeType::hold);
    fr.setStopping(brakeType::hold);
    mr.setStopping(brakeType::hold);
    br.setStopping(brakeType::hold);
  }
}

void driveTask::setdrivespeed(bool slow)
{
  previousslow = currentslow;
  currentslow = slow;
  if(!previousslow && currentslow)
  {
    slowno++;
  }
  if(slowno % 2 == 0)
  {
    speedconst = 1;
  }
  else 
  {
    speedconst = 0.1;
  }
}
//thread for drive subsystem
void driveTask::drivethread()
{
  while(true)
  {
    lefty = Controller1.Axis3.value();
    leftx = Controller1.Axis4.value();
    x = Controller1.ButtonX.pressing();
    uarrow = Controller1.ButtonUp.pressing();
    setdrivespeed(uarrow);
    drive(lefty, leftx);
    stophold(x);
    wait(10, msec);
  }
}