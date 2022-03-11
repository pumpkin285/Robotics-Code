#include "vex.h"
#include "../include/definitions/init.h"
#include "definitions/autonomous.h"

void setbrake()
{
  fl.setStopping(coast);
  ml.setStopping(coast);
  bl.setStopping(coast);
  fr.setStopping(coast);
  mr.setStopping(coast);
  br.setStopping(coast);
  fb.setStopping(hold);
  conveyor.setStopping(hold);
}

void resetposition()
{
  fl.resetPosition();
  ml.resetPosition();
  bl.resetPosition();
  fr.resetPosition();
  mr.resetPosition();
  br.resetPosition();
  fb.resetPosition();
}

void printscreen()
{
  while(true)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(fb.position(deg));
    Brain.Screen.setCursor(2,1);
    Brain.Screen.print(lefterror[0]);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print(righterror[0]);
    Brain.Screen.setCursor(4,1);
    Brain.Screen.print(in.rotation());
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print(fb.position(deg));
    Brain.Screen.setCursor(6,1);
    Brain.Screen.print(automode);
    wait(50, msec);
  }
}