#include "vex.h"
#include "../include/definitions/tasks.h"
#include "robot-config.h"

double fwpow, turnpow;
double leftpower, rightpower; 
void driverTasks::chassis(double fw, double turn, bool hold, bool unhold)
{
  fwpow = fw;
  turnpow = turn * 0.85;
  leftpower = fwpow + turnpow;
  rightpower = fwpow - turnpow;
  fl.spin(fwd, leftpower, pct);
  bl.spin(fwd, leftpower, pct);
  fr.spin(fwd, rightpower, pct);
  br.spin(fwd, rightpower, pct);
  if(hold == true)
  {
    fl.setBrake(vex::brakeType::hold);
    fr.setBrake(vex::brakeType::hold);
    bl.setBrake(vex::brakeType::hold);
    br.setBrake(vex::brakeType::hold);
  }
  else if(unhold == true)
  {
    fl.setBrake(vex::brakeType::coast);
    fr.setBrake(vex::brakeType::coast);
    bl.setBrake(vex::brakeType::coast);
    br.setBrake(vex::brakeType::coast);

  }
}