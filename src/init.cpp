//file for initialization functions, as well as the print screen

#include "definitions/autonomous.h"
#include "vex.h"
#include "robot-config.h"
#include "definitions/opcontrol.h"
#include "definitions/init.h"

void resetposition()
{
  fl.resetPosition();
  ml.resetPosition();
  bl.resetPosition();
  fr.resetPosition();
  mr.resetPosition();
  br.resetPosition();
  fb.resetPosition();
  conveyor.resetPosition();
}

void calibrate()
{
  xtrack.resetRotation();
  ytrack.resetRotation();
  //in1.calibrate();
  in2.calibrate();
  while(in2.isCalibrating())
  {
    wait(10, msec);
  }
}

void setbrake()
{
  fl.setBrake(coast);
  ml.setBrake(coast);
  bl.setBrake(coast);
  fr.setBrake(coast);
  mr.setBrake(coast);
  br.setBrake(coast);
  fb.setBrake(hold);
  conveyor.setBrake(coast);
}

void printscreen()
{
  while(true)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(point);
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print("x tracking wheel: %f", leftwheelpower);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print("y tracking wheel: %f", rightwheelpower);
    Brain.Screen.setCursor(4,1);
    Brain.Screen.print("inertial: %f", curvature);
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print("x coordinate: %f", qbezpoint[0][0]);
    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print("y coordinate: %f", qbezpoint[0][1]);
    Brain.Screen.setCursor(7, 1);
    Brain.Screen.print("x coordinate: %f", lookaheadhdis);
    Brain.Screen.setCursor(8, 1);
    Brain.Screen.print("y coordinate: %f", lookaheaddistance);
    Brain.Screen.setCursor(9, 1);
    Brain.Screen.print("x coordinate: %f", headingdeg);
    
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);
    Controller1.Screen.print(speedconst);
    Controller1.Screen.setCursor(2, 1);
    Controller1.Screen.print(currenty);
    Controller1.Screen.setCursor(3, 1);
    Controller1.Screen.print(headingdeg);
    
    wait(100, msec);
  }
}