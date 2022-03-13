#include "vex.h"
#include "../include/definitions/initialize.h"
#include "../include/definitions/tasks.h"

void setbrake()
{
  fl.setStopping(coast);
  fr.setStopping(coast);
  bl.setStopping(coast);
  br.setStopping(coast);
  //fc.setStopping(hold);
  fb.setStopping(hold);
  bmr.setStopping(hold);
  bml.setStopping(hold);
}

void resetposition()
{
  fl.resetPosition();
  fr.resetPosition();
  bl.resetPosition();
  br.resetPosition();
  //fc.resetPosition();
  fb.resetPosition();
  bml.resetPosition();
  bmr.resetPosition();

}

void printscreen() 
{
  while(true)
  {
    Brain.Screen.clearScreen();
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print(in.yaw(deg));
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print(lefterror[0]);
    Brain.Screen.setCursor(3, 1);
    Brain.Screen.print(righterror[0]);
    Brain.Screen.setCursor(4, 1);
    Brain.Screen.print(headingerror[0]);
    Brain.Screen.setCursor(5, 1);
    Brain.Screen.print(r1);
    Brain.Screen.setCursor(6, 1);
    Brain.Screen.print(r2);
    wait(10, msec);
  }

}

