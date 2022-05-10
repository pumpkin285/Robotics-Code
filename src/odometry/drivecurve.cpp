//file for pure pursuit, curve pathing

#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"
#include "definitions/init.h"
#include "math.h"
double trackwidth = 10;
double maxpointerror = 0.5;
bool purepid, startaccel;
double cbezpoint[10][2], qbezpoint[10][2], curvature, targetvelocity;
double leftpurewheelpower, rightpurewheelpower, prevfinalgoaldistance, finalgoaldistance; 
double c1x, c1y, c2x, c2y, q1x, q1y, t, point, lookaheadx, lookaheady, offsetheading, lookaheadheading, lookaheaddistance, lookaheadhdis;
double equa, equb, equc; //robot line equation coefficients

double purekP = 0.055;
double leftpurekD = -1.4;
double rightpurekD = -1.4;

void pure::cpathgen()
{
  for(int i = 1; i <= 10; i++)
  {
    t = i * 0.1;
    cbezpoint[i-1][0] = pow(1-t,3) * startx + pow(1-t,2) * t * c1x + (1-t) * pow(t,2) * c2x + pow(t,3) * goalx;
    cbezpoint[i-1][1] = pow(1-t,3) * starty + pow(1-t,2) * t * c1y + (1-t) * pow(t,2) * c2y + pow(t,3) * goaly;
  }
  Controller1.Screen.print(1);
}

void pure::qpathgen()
{
  for(int i = 1; i <= 10; i++)
  {
    t = i * 0.1;
    qbezpoint[i-1][0] = pow(1-t,2) * startx + (1-t) * t * q1x + pow(t,2) * goalx;
    qbezpoint[i-1][1] = pow(1-t,2) * starty + (1-t) * t * q1y + pow(t,2) * goaly;
  }
  Controller1.Screen.print(1);
}


void pure::bezpathfollow()
{
  prevfinalgoaldistance = finalgoaldistance;
  finalgoaldistance = sqrt(pow(goaly - currenty,2) + pow(goalx - currentx,2));
  lookaheadheading = autoTask::calcheading(currentx, currenty, lookaheadx, lookaheady);
  lookaheaddistance = sqrt(pow(lookaheady - currenty,2) + pow(lookaheadx - currentx,2));
  offsetheading = fabs(lookaheadheading - heading);  
  curvature = 2 * sin(offsetheading) / lookaheaddistance;
  if(lookaheadheading < headingdeg)
  {
    curvature = -curvature;
  }
  if(purepid)
  {
    if(point >= 8)
    {
      leftwheelpower = autoTask::motorpower(finalgoaldistance, prevfinalgoaldistance, purekP, leftpurekD);
      rightwheelpower = autoTask::motorpower(finalgoaldistance, prevfinalgoaldistance, purekP, rightpurekD);
    }
    else 
    {
      leftwheelpower = maxpower;
      rightwheelpower = maxpower;
    }
  }
  else 
  {
    leftwheelpower = maxpower;
    rightwheelpower = maxpower;
  }
  leftpurewheelpower = leftwheelpower * (2 + curvature * trackwidth) / 2;
  rightpurewheelpower = rightwheelpower * (2 - curvature * trackwidth) / 2;
  maxaccel = accel * loopnumber;
  leftactualwheelpower = autoTask::min(1000, leftpurewheelpower, maxaccel);
  rightactualwheelpower = autoTask::min(1000, rightpurewheelpower, maxaccel);
  /*
  fl.spin(fwd, directionconst * leftactualwheelpower, pct);
  ml.spin(fwd, directionconst * leftactualwheelpower, pct);
  bl.spin(fwd, directionconst * leftactualwheelpower, pct);
  fr.spin(fwd, directionconst * rightactualwheelpower, pct);
  mr.spin(fwd, directionconst * rightactualwheelpower, pct);
  br.spin(fwd, directionconst * rightactualwheelpower, pct);
  */
  loopnumber ++;
}

void pure::cubic(double cube1x, double cube1y, double cube2x, double cube2y, double goalx1, double goaly1, bool startaccel1, bool endstop1)
{
  startaccel = startaccel1;
  purepid = endstop1;
  startx = currentx;
  starty = currenty;
  c1x = cube1x;
  c1y = cube1y;
  c2x = cube2x;
  c2y = cube2y;
  goalx = goalx1;
  goaly = goaly1;
  drivemode = 6;
  wait(10, msec);
  for(int i = 0; i < 10; i++)
  {
    lookaheadx = cbezpoint[i][0];
    lookaheady = cbezpoint[i][1];
    while(lookaheaddistance > maxpointerror)
    {
      wait(10, msec);
    }
  }
  drivemode = 1;
}

void pure::quadratic(double quad1x, double quad1y, double goalx1, double goaly1, bool startaccel1, bool endstop1)
{
  startaccel = startaccel1;
  purepid = endstop1;
  startx = currentx;
  starty = currenty;
  q1x = quad1x;
  q1y = quad1y;
  goalx = goalx1;
  goaly = goaly1;
  drivemode = 8;
  wait(50, msec);
  for(int i = 0; i < 10; i++)
  {
    point = i;
    lookaheadx = qbezpoint[i][0];
    lookaheady = qbezpoint[i][1];
    wait(10, msec);
    while(lookaheaddistance > maxpointerror)
    {
      wait(10, msec);
    }
  }
  drivemode = 1;
}