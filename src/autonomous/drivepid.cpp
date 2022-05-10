//file for normal pid functions, drive fwd and turn

#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"
#include "definitions/init.h"
#include "math.h"
int directionconst;
double leftwheelpower, leftactualwheelpower, rightwheelpower, rightactualwheelpower;
double lefterror[drivedelay], righterror[drivedelay], headingerror[turndelay];

double goal, previousheading, currentheading, maxpower, accel, maxaccel;
double gyroturnkP = 0.63;
double gyroturnkD = 0.2;
double drivekP = 0.055;
double leftdrivekD = 1.4;
double rightdrivekD = 1.4;
double twomogoturnkP = 0.45;
double twomogoturnkD = 0.2;

void autoTask::gyroturn()
{
  currenttime = Brain.Timer.time(sec);
  leftwheelpower = motorpower(headingerror[0], headingerror[1], gyroturnkP, gyroturnkD);
  rightwheelpower = motorpower(headingerror[0], headingerror[1], gyroturnkP, gyroturnkD);
  maxaccel = accel * loopnumber;
  leftactualwheelpower = min(leftwheelpower, maxaccel, maxpower);
  rightactualwheelpower = min(rightwheelpower, maxaccel, maxpower);
  fl.spin(fwd, directionconst * leftactualwheelpower, pct);
  ml.spin(fwd, directionconst * leftactualwheelpower, pct);
  bl.spin(fwd, directionconst * leftactualwheelpower, pct);
  fr.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
  mr.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
  br.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
  for(int i = turndelay - 1; i > 0; i--)
  {
    headingerror[i] = headingerror[(i - 1)];
  }
  headingerror[0] = (goalheading - headingdeg) * directionconst;
  //Brain.Screen.clearScreen();
  loopnumber++;
}

void autoTask::twomogoturn()
{
  currenttime = Brain.Timer.time(sec);
  leftwheelpower = motorpower(headingerror[0], headingerror[1], twomogoturnkP, twomogoturnkD);
  rightwheelpower = motorpower(headingerror[0], headingerror[1], twomogoturnkP, twomogoturnkD);
  maxaccel = accel * loopnumber;
  leftactualwheelpower = min(leftwheelpower, maxaccel, maxpower);
  rightactualwheelpower = min(rightwheelpower, maxaccel, maxpower);
  fl.spin(fwd, directionconst * leftactualwheelpower, pct);
  ml.spin(fwd, directionconst * leftactualwheelpower, pct);
  bl.spin(fwd, directionconst * leftactualwheelpower, pct);
  fr.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
  mr.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
  br.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
  for(int i = turndelay - 1; i > 0; i--)
  {
    headingerror[i] = headingerror[(i - 1)];
  }
  headingerror[0] = (goalheading - headingdeg) * directionconst;
  //Brain.Screen.clearScreen();
  loopnumber++;
}

void autoTask::drive()
{
  //pid calculations
  currenttime = Brain.Timer.time(sec);
  leftwheelpower = fabs(motorpower(lefterror[0], lefterror[1], drivekP, leftdrivekD));
  rightwheelpower = fabs(motorpower(righterror[0], righterror[1], drivekP, rightdrivekD));
  maxaccel = accel * loopnumber; //maximum acceleration at the start of the movements
  leftactualwheelpower = 0.98 * min(leftwheelpower, maxaccel, maxpower);
  rightactualwheelpower = 1.04 * min(rightwheelpower, maxaccel, maxpower);

  fl.spin(fwd, directionconst * leftactualwheelpower, pct);
  ml.spin(fwd, directionconst * leftactualwheelpower, pct);
  bl.spin(fwd, directionconst * leftactualwheelpower, pct);
  fr.spin(fwd, directionconst * rightactualwheelpower, pct);
  mr.spin(fwd, directionconst * rightactualwheelpower, pct);
  br.spin(fwd, directionconst * rightactualwheelpower, pct);
  //refresh the array of errors, in order to do more accurate pid
  for(int i = drivedelay - 1; i > 0; i--)
  {
    lefterror[i] = lefterror[i - 1];
    righterror[i] = righterror[i - 1];
  }
  lefterror[0] = endenc + ytrack.position(deg);
  righterror[0] = endenc + ytrack.position(deg);
  loopnumber++;
}

