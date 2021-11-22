#include "vex.h"
#include "math.h"
#include "../../include/definitions/tasks.h"

double goal, previousheading, currentheading;
double setpointdeg, starttime, currenttime, timecount, accel, maxaccel, leftavg, rightavg;
double leftwheelpower, leftactualwheelpower, rightwheelpower, rightactualwheelpower;
int directionconst, loopexit, loopnumber;
double lefterror[drivedelay], righterror[drivedelay], headingerror[turndelay];
double gyroturnkP = 1.12;
double gyroturnkD = 0.15;
double drivekP = 0.25;
double leftdrivekD = 0.1;
double rightdrivekD = 0.15;
double drivedelaytime = 10;
double turndelaytime = 10;
double  drivemaxerror = 1;
double  turnmaxerror = 0.5;
double startmogoposition;

void autoTasks::drive(double distance, double maxpower, int direction, double maxtime)
{  //setpoint is always a positive number
  setpointdeg = distance / (4 * M_PI / 360);
  drivereset();
  starttime = Brain.Timer.time();
  timecount = 0;
  switch(direction)
  /*
  1 = forward
  2 = backward
  */
  {
    case 1:
    directionconst = 1;
    accel = 2;
    break;
    case 2:
    directionconst = -1;
    accel = 2;
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
  loopexit = 0;
  loopnumber = 1;
  while(timecount < 1000 * maxtime)
  {
    leftwheelpower = fabs(motorpower((-1) * lefterror[0], (-1) * lefterror[1], drivekP, leftdrivekD));
    rightwheelpower = fabs(motorpower((-1) * righterror[0], (-1) * righterror[1], drivekP, rightdrivekD));
    maxaccel = accel * loopnumber;
    leftactualwheelpower = min(leftwheelpower, maxaccel, maxpower);
    rightactualwheelpower = min(rightwheelpower, maxaccel, maxpower);

    fl.spin(fwd, directionconst * leftactualwheelpower, pct);
    bl.spin(fwd, directionconst * leftactualwheelpower, pct);
    fr.spin(fwd, directionconst * rightactualwheelpower, pct);
    br.spin(fwd, directionconst * rightactualwheelpower, pct);
    leftavg = directionconst * (fl.position(deg) + bl.position(deg)) / 2;
    rightavg = directionconst * (fr.position(deg) + br.position(deg)) / 2;
    for(int i = drivedelay - 1; i > 0; i--)
    {
      lefterror[i] = lefterror[i - 1];
      righterror[i] = righterror [i - 1];
    }
    lefterror[0] = leftavg - setpointdeg;
    righterror[0] = rightavg - setpointdeg;
    wait(drivedelaytime, msec);
    loopexit = 1;
    for(int i = 0; i < drivedelay; i++)
    {
      if(fabs(lefterror[i]) > drivemaxerror)
      {
        loopexit = 0;
      }
      if(fabs(righterror[i]) > drivemaxerror)
      {
        loopexit = 0;
      }
    }
    if(loopexit == 1)
    {
      break;
    }
    currenttime = Brain.Timer.time();
    timecount = currenttime - starttime;
    loopnumber++;
  }
  drivestop();
  drivereset();
}

void autoTasks::drivebackmogo(double distance, double maxpower, int direction, double maxtime, double startmogo, double backmogovalue, double backmogovelocity)
{  //setpoint is always a positive number
  setpointdeg = distance / (4 * M_PI / 360);
  startmogoposition = startmogo / (4 * M_PI / 360);
  drivereset();
  starttime = Brain.Timer.time();
  timecount = 0;
  switch(direction)
  /*
  1 = forward
  2 = backward
  */
  {
    case 1:
    directionconst = 1;
    accel = 2;
    break;
    case 2:
    directionconst = -1;
    accel = 2;
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
  loopexit = 0;
  loopnumber = 1;
  while(timecount < 1000 * maxtime)
  {
    leftwheelpower = fabs(motorpower((-1) * lefterror[0], (-1) * lefterror[1], drivekP, leftdrivekD));
    rightwheelpower = fabs(motorpower((-1) * righterror[0], (-1) * righterror[1], drivekP, rightdrivekD));
    maxaccel = accel * loopnumber;
    leftactualwheelpower = min(leftwheelpower, maxaccel, maxpower);
    rightactualwheelpower = min(rightwheelpower, maxaccel, maxpower);

    fl.spin(fwd, directionconst * leftactualwheelpower, pct);
    bl.spin(fwd, directionconst * leftactualwheelpower, pct);
    fr.spin(fwd, directionconst * rightactualwheelpower, pct);
    br.spin(fwd, directionconst * rightactualwheelpower, pct);
    if(bml.position(deg) > backmogovalue && startmogoposition > fabs(lefterror[0]))
    {
      bml.spin(reverse, backmogovelocity, pct);
      bmr.spin(reverse, backmogovelocity, pct);
    }
    else
    {
      bml.stop();
      bmr.stop();
    }
    leftavg = directionconst * (fl.position(deg) + bl.position(deg)) / 2;
    rightavg = directionconst * (fr.position(deg) + br.position(deg)) / 2;
    for(int i = drivedelay - 1; i > 0; i--)
    {
      lefterror[i] = lefterror[i - 1];
      righterror[i] = righterror [i - 1];
    }
    lefterror[0] = leftavg - setpointdeg;
    righterror[0] = rightavg - setpointdeg;
    wait(drivedelaytime, msec);
    loopexit = 1;
    for(int i = 0; i < drivedelay; i++)
    {
      if(fabs(lefterror[i]) > drivemaxerror)
      {
        loopexit = 0;
      }
      if(fabs(righterror[i]) > drivemaxerror)
      {
        loopexit = 0;
      }
    }
    if(loopexit == 1)
    {
      break;
    }
    currenttime = Brain.Timer.time();
    timecount = currenttime - starttime;
    loopnumber++;
  }
  while(bml.position(deg) > backmogovalue)
  {
    bml.spin(reverse, backmogovelocity, pct);
    bmr.spin(reverse, backmogovelocity, pct);
    wait(10, msec);
  }
  bml.stop();
  bmr.stop();
  drivestop();
  drivereset();

}

void autoTasks::gyroturn(double setpoint, double maxpower, int direction, double timelimit)
{
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
    headingerror[i] = setpoint;
  }
  loopexit = 0;
  while(timecount < 1000 * timelimit)
  {
    leftwheelpower = motorpower(headingerror[0], headingerror[1], gyroturnkP, gyroturnkD);
    rightwheelpower = motorpower(headingerror[0], headingerror[1], gyroturnkP, gyroturnkD);
    maxaccel = accel * loopnumber;
    leftactualwheelpower = min(leftwheelpower, maxaccel, maxpower);
    rightactualwheelpower = min(rightwheelpower, maxaccel, maxpower);
    fl.spin(fwd, directionconst * leftactualwheelpower, pct);
    bl.spin(fwd, directionconst * leftactualwheelpower, pct);
    fr.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
    br.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
    currentheading = in.rotation(deg);
    for(int i = turndelay - 1; i > 0; i--)
    {
      headingerror[i] = headingerror[(i - 1)];
    }
    headingerror[0] = (setpoint - currentheading) * directionconst;
    wait(turndelaytime, msec);
    Brain.Screen.clearScreen();
    loopexit = 1;
    for(int i = 0; i < turndelay; i++)
    {
      if(fabs(headingerror[i]) > turnmaxerror)
      {
        loopexit = 0;
      }
    }
    if(loopexit == 1)
    {
      break;
    }
    loopnumber++;
    currenttime = Brain.Timer.time(msec);
    timecount = currenttime - starttime;
  }
  drivestop();
  Brain.Screen.clearScreen();
  drivestop();
}

void autoTasks::gyroturnback(double setpoint, double maxpower, int direction, double timelimit, double backmogovalue, double backmogovelocity)
{
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
    headingerror[i] = setpoint;
  }
  loopexit = 0;
  while(timecount < 1000 * timelimit)
  {
    leftwheelpower = motorpower(headingerror[0], headingerror[1], gyroturnkP, gyroturnkD);
    rightwheelpower = motorpower(headingerror[0], headingerror[1], gyroturnkP, gyroturnkD);
    maxaccel = accel * loopnumber;
    leftactualwheelpower = min(leftwheelpower, maxaccel, maxpower);
    rightactualwheelpower = min(rightwheelpower, maxaccel, maxpower);
    fl.spin(fwd, directionconst * leftactualwheelpower, pct);
    bl.spin(fwd, directionconst * leftactualwheelpower, pct);
    fr.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
    br.spin(fwd, directionconst * (-1) * rightactualwheelpower, pct);
    if(bml.position(deg) > backmogovalue)
    {
      bml.spin(reverse, backmogovelocity, pct);
      bmr.spin(reverse, backmogovelocity, pct);
    }
    currentheading = in.rotation(deg);
    for(int i = turndelay - 1; i > 0; i--)
    {
      headingerror[i] = headingerror[(i - 1)];
    }
    headingerror[0] = (setpoint - currentheading) * directionconst;
    wait(turndelaytime, msec);
    Brain.Screen.clearScreen();
    loopexit = 1;
    for(int i = 0; i < turndelay; i++)
    {
      if(fabs(headingerror[i]) > turnmaxerror)
      {
        loopexit = 0;
      }
    }
    if(loopexit == 1)
    {
      break;
    }
    loopnumber++;
    currenttime = Brain.Timer.time(msec);
    timecount = currenttime - starttime;
  }
  drivestop();
  while(bml.position(deg) > backmogovalue)
    {
      bml.spin(reverse, backmogovelocity, pct);
      bmr.spin(reverse, backmogovelocity, pct);
    }
  bml.stop();
  bmr.stop();
  Brain.Screen.clearScreen();
}