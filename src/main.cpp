/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cyiuh                                            */
/*    Created:      Fri Dec 17 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "../include/definitions/init.h"
#include "../include/definitions/opcontrol.h"
#include "../include/definitions/autonomous.h"
//vex::thread driveauton;
bool right1[6], right2[6];
using namespace vex;
driverTasks drived;
autonTasks autos;
void initialize()
{
  resetposition();
  setbrake();
  fc.set(true);
  for(int i = 0; i < 6; i++)
  {
    right1[i] = false;
    right2[i] = false;
  }
  holdno = 0;
  backlift.set(true);
  vex::thread pscreen(printscreen);
  drivemode = 1;
  fbmode = 1;
  fcmode = 2;
  backmode = 1;
  conveyorvelocity = 70;
  fbvelocity = 80;
  maxpower = 200;
  autos.calibrate();
}

void opcontrol()
{
  //set the auton modes to be not affecting the driver control tasks
  fbmode = 0;
  drivemode = 0;
  fcmode = 0;
  ringmode = 0;
  backmode = 0;
  vex::thread driver(drived.driving);
  vex::thread frontmogo(drived.front);
  vex::thread backmogo(drived.back);
  vex::thread conveyor1(drived.ring);
}

void auton()
{
  resetposition();
  vex::thread driver(autos.driving);
  vex::thread frontmogo(autos.front);
  vex::thread backmogo(autos.back);
  vex::thread conveyor1(autos.ring);    
  //autos.calibrate();
  automode = 4; //choose auton mode here
  /*
  1: test
  2: awp
  3: down
  4: up
  5: skills
  */
  autos.mainauton();
}

vex::competition competition1;
int main() {
  vexcodeInit();
  
   initialize();
  /*
  competition1.drivercontrol(opcontrol);
  competition1.autonomous(auton);
  
  while(true)
  {
    wait(10, msec);
  }
  
  //uncomment above to do normal driving
  //uncomment below to do testing
  */
  
  vex::thread driveauton(autos.driving);
  vex::thread frontauton(autos.front);
  vex::thread backauton(autos.back);
  vex::thread ringauton(autos.ring);
  while(true)
  {
    wait(10, msec);
    if(Controller1.ButtonUp.pressing())
    {
      automode = 1;
      break;
    }
    else if(Controller1.ButtonRight.pressing())
    {
      automode = 2;
      break;
    }
    else if(Controller1.ButtonDown.pressing())
    {
      automode = 3;
      break;
    }
    else if(Controller1.ButtonLeft.pressing())
    {
      automode = 4;
      break;
    }
    else if(Controller1.ButtonX.pressing())
    {
      automode = 5;
     
      break;
    }
    else if(Controller1.ButtonY.pressing())
    {
      automode = 6;
      break;
    }
  }

  autos.mainauton();
  
}
