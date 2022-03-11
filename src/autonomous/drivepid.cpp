//pid functions during auton
#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"

double setpointdeg, starttime, currenttime, timecount, accel, maxaccel, leftavg, rightavg;
double leftwheelpower, leftactualwheelpower, rightwheelpower, rightactualwheelpower;
int directionconst, loopexit, loopnumber, direction;
double goal, previousheading, currentheading, maxpower;
double lefterror[drivedelay], righterror[drivedelay], headingerror[turndelay];
double gyroturnkP = 0.9;
double gyroturnkD = 0.15;
double gyroturnmogokP = 0.925;
double gyroturnmogokD = 0.16;
double drivekP = 0.12;
double leftdrivekD = 0.2;
double rightdrivekD = 0.25;
double drivedelaytime = 10;
double turndelaytime = 10;
double  drivemaxerror = 1;
double  turnmaxerror = 0.5;
double doublemogokP = 0.12;
double doublemogoleftkD = 0.15;
double doublemogorightkD = 0.2;

void autonTasks::drive()
{ 
  //pid calculations
  leftwheelpower = fabs(motorpower((-1) * lefterror[0], (-1) * lefterror[1], drivekP, leftdrivekD));
  rightwheelpower = fabs(motorpower((-1) * righterror[0], (-1) * righterror[1], drivekP, rightdrivekD));
  maxaccel = accel * loopnumber;
  leftactualwheelpower = min(leftwheelpower, maxaccel, maxpower);
  rightactualwheelpower = min(rightwheelpower, maxaccel, maxpower);

  fl.spin(fwd, directionconst * leftactualwheelpower, pct);
  ml.spin(fwd, directionconst * leftactualwheelpower, pct);
  bl.spin(fwd, directionconst * leftactualwheelpower, pct);
  fr.spin(fwd, directionconst * rightactualwheelpower, pct);
  mr.spin(fwd, directionconst * rightactualwheelpower, pct);
  br.spin(fwd, directionconst * rightactualwheelpower, pct);
  leftavg = directionconst * (fl.position(deg) + bl.position(deg)) / 2;
  rightavg = directionconst * (fr.position(deg) + br.position(deg)) / 2;
  //refresh the array of errors, in order to do more accurate pid
  for(int i = drivedelay - 1; i > 0; i--)
  {
    lefterror[i] = lefterror[i - 1];
    righterror[i] = righterror [i - 1];
  }
  lefterror[0] = leftavg - setpointdeg;
  righterror[0] = rightavg - setpointdeg;
  wait(drivedelaytime, msec);
  loopnumber++;
}

void autonTasks::gyroturn()
{
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
  currentheading = in.rotation(deg);
  for(int i = turndelay - 1; i > 0; i--)
  {
    headingerror[i] = headingerror[(i - 1)];
  }
  headingerror[0] = (goal - currentheading) * directionconst;
  Brain.Screen.clearScreen();
  loopnumber++;
}

void autonTasks::drivestop()
{
  fl.stop();
  ml.stop();
  bl.stop();
  fr.stop();
  mr.stop();
  br.stop();
}

double autonTasks::motorpower(double currenterror, double previouserror, float kP, float kD)
{
  float pterm = currenterror * kP;
  float dterm = (currenterror - previouserror) * kD;
  float power = pterm + dterm;
  return power;
}

double autonTasks::min(double value1, double value2, double value3)
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
void autonTasks::drivereset()
{
  fl.resetPosition();
  ml.resetPosition();
  bl.resetPosition();
  fr.resetPosition();
  mr.resetPosition();
  br.resetPosition();
}


