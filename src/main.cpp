/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cyiuh                                            */
/*    Created:      Sat Mar 12 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
#include "definitions/opcontrol.h"
#include "definitions/autonomous.h"
#include "definitions/init.h"
using namespace vex;

competition competition1;
driveTask drivetasks;
autoTask autotasks;
positiontrack odom;

void init()
{
  holdno = 0;
  conveyorno = 0;
  resetposition();
  setbrake();
  fc.set(true);
  drivemode = 1;
  fbmode = 1;
  fcmode = 2;
  backmode = 2;
  ringmode = 1;
  fbvelocity = 100;
  maxpower = 100;
  calibrate();
  //in1.resetRotation();
  in2.resetRotation();
  thread pscreen(printscreen);
  thread odom1(odom.globalposition);
}

void auton()
{
  resetposition();
  automode = 2; //SET AUTO MODE HERE
  setring = true;
  xtrack.resetRotation();
  ytrack.resetRotation();
  thread drive1(autotasks.driving);
  thread frontclaw1(autotasks.frontclaw);
  thread fourbar1(autotasks.fourbar);
  thread backclaw1(autotasks.back);
  thread conveyor1(autotasks.intaking);
  autotasks.mainauto();
}

void opcontrol()
{
  drivemode = 0;
  fbmode = 0;
  fcmode = 0;
  backmode = 0;
  ringmode = 0;
  setring = false;
  //set all auton modes to 0 so that the threads for auton does not interfere
  thread drive1(drivetasks.drivethread);
  thread claw1(drivetasks.clawthread);
  thread conveyor1(drivetasks.ringthread);
  thread fourbar1(drivetasks.fourbarthread);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  competition1.drivercontrol(opcontrol);
  competition1.autonomous(auton);
  init();
  
  while(true)
  {
    wait(10, msec);
  }
  
  //uncomment above to normal
  //uncomment below to testing
  /*
  thread frontclawauton(autotasks.frontclaw);
  thread fourbarauton(autotasks.fourbar);
  thread backauton(autotasks.back);
  thread ringauton(autotasks.intaking);
  thread driveauton(autotasks.driving);
  init();
  while(true)
  {
    this_thread::sleep_for(10);
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
    wait(10, msec);
  }
  autotasks.mainauto();
  */
}
