//this file for the driving thread, only the chassis and the stop hold function

#include "vex.h"
#include "robot-config.h"
#include "../../include/definitions/opcontrol.h"

double fwpow, turnpow, leftpow, rightpow;
double leftx, lefty;
bool currentx, previousx;
int holdno;

void driverTasks::chassis(double fw, double turn, bool currenthold, bool previoushold)
{
  fwpow = fw;
  turnpow = 0.85 * turn;
  //sensivity controls, for turns
  leftpow = fwpow + turnpow; 
  rightpow = fwpow - turnpow;
  //motors turn in different direction for left and right
  fl.spin(fwd, leftpow, pct);
  ml.spin(fwd, leftpow, pct);
  bl.spin(fwd, leftpow, pct);
  fr.spin(fwd, rightpow, pct);
  mr.spin(fwd, rightpow, pct);
  br.spin(fwd, rightpow, pct);

  if(currenthold == true && previoushold == false)
  {
    holdno += 1;
  }
  if(holdno % 2 == 1)
  {
    fl.setBrake(vex::brakeType::hold);
    ml.setBrake(vex::brakeType::hold);
    bl.setBrake(vex::brakeType::hold);
    fr.setBrake(vex::brakeType::hold);
    mr.setBrake(vex::brakeType::hold);
    br.setBrake(vex::brakeType::hold);
    //set stop hold if x is pressed odd number of times
  }
  else
  {
    fl.setBrake(vex::brakeType::coast);
    ml.setBrake(vex::brakeType::coast);
    bl.setBrake(vex::brakeType::coast);
    fr.setBrake(vex::brakeType::coast);
    mr.setBrake(vex::brakeType::coast);
    br.setBrake(vex::brakeType::coast);
    //set stop coast, become normal if x is pressed even number of times
  }
}

void driverTasks::driving()
{
  //thread for driving
  while(true)
  {
    leftx = Controller1.Axis4.value();
    lefty = Controller1.Axis3.value();
    previousx = currentx;
    currentx = Controller1.ButtonX.pressing();
    chassis(lefty, leftx, currentx, previousx);
    wait(10, msec);
  }
}