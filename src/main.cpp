/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cyiuh                                            */
/*    Created:      Sat Oct 23 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// fl                   motor         8               
// fr                   motor         3               
// bl                   motor         9               
// br                   motor         2               
// fc                   motor         20              
// fb                   motor         6               
// bml                  motor         7               
// bmr                  motor         5               
// in                   inertial      4               
// piston               digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "../include/definitions/initialize.h"
#include "../include/definitions/tasks.h"

competition competition1;
driverTasks drivetask;
autoTasks autotask;
using namespace vex;
int automodes;
void initialize() {
  fc.set(true);
  bc.set(true);
  resetposition();
  setbrake();
  vex::thread pscreen(printscreen);
  autotask.calibrate();
}

void auton()
{
  setbrake();
  resetposition();
  autotask.mainauto(3);
}
void opcontrol()
{
  setbrake();
  
  
  while(true)
  {
    
    drivetask.driving();
    drivetask.back();
    drivetask.front();
    drivetask.setbackclaw();
    wait(10, msec);
  }
  
}
int main() {
  vexcodeInit(); 
  
  competition1.drivercontrol(opcontrol);
  competition1.autonomous(auton);
  
  initialize();
  
  while(true)
  {
    wait(10, msec);
  }
  
  /*
  while(true)
  {
    this_thread::sleep_for(10);
    if(Controller1.ButtonUp.pressing())
    {
      automodes = 1;
      break;
    }
    else if(Controller1.ButtonRight.pressing())
    {
      automodes = 2;
      break;
    }
    else if(Controller1.ButtonDown.pressing())
    {
      automodes = 3;
      break;
    }
    else if(Controller1.ButtonLeft.pressing())
    {
      automodes = 4;
      break;
    }
    else if(Controller1.ButtonX.pressing())
    {
      automodes = 5;
      break;
    }
    else if(Controller1.ButtonY.pressing())
    {
      automodes = 6;
    }
  }
  autotask.mainauto(automodes);
  */
}

