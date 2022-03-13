/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\cyiuh                                            */
<<<<<<< HEAD
/*    Created:      Fri Dec 17 2021                                           */
=======
/*    Created:      Sat Oct 23 2021                                           */
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
<<<<<<< HEAD
=======
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
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "robot-config.h"
<<<<<<< HEAD
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
=======
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
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
}

void auton()
{
<<<<<<< HEAD
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
  
=======
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
  
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
  while(true)
  {
    wait(10, msec);
  }
  
<<<<<<< HEAD
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
=======
  /*
  while(true)
  {
    this_thread::sleep_for(10);
    if(Controller1.ButtonUp.pressing())
    {
      automodes = 1;
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
      break;
    }
    else if(Controller1.ButtonRight.pressing())
    {
<<<<<<< HEAD
      automode = 2;
=======
      automodes = 2;
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
      break;
    }
    else if(Controller1.ButtonDown.pressing())
    {
<<<<<<< HEAD
      automode = 3;
=======
      automodes = 3;
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
      break;
    }
    else if(Controller1.ButtonLeft.pressing())
    {
<<<<<<< HEAD
      automode = 4;
=======
      automodes = 4;
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
      break;
    }
    else if(Controller1.ButtonX.pressing())
    {
<<<<<<< HEAD
      automode = 5;
     
=======
      automodes = 5;
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
      break;
    }
    else if(Controller1.ButtonY.pressing())
    {
<<<<<<< HEAD
      automode = 6;
      break;
    }
  }

  autos.mainauton();
  
}
=======
      automodes = 6;
    }
  }
  autotask.mainauto(automodes);
  */
}

>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
