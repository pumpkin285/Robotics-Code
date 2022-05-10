//file for autonomous routes

#include "vex.h"
#include "robot-config.h"
#include "definitions/init.h"
#include "definitions/autonomous.h"

int automode;
bool setring;

void autoTask::testing()
{
  maxpower = 50;
  //pure::quadratic(0, 24, 24, 24, 1, 1);
  //drivefwd(24,2);
  turn(-45,1);
}

void autoTask::downmogorush()
{
  maxpower = 120;
  fcmode = 1;
  drivefwdtime(51, 1.05);
  fcmode = 2;
  maxpower = 100;
  backmode = 3;
  drivefwd(-32, 15);
  /*
  turn(23, 0.7);
  drivefwd(-18, 1.4);
  turn(-96, 1);
  
  drivefwdtime(-17, 0.9);
  backmode = 2;
  wait(0.2, sec);
  turn(-65, 0.5);
  drivefwdtime(8, 0.6);
  ringvelocity = 85;
  ringmode = 2;
  
  maxpower = 15;
  drivefwdtime(20, 3);
  maxpower = 80;
  drivefwdtime(-18, 1);
  wait(1, sec);
  maxpower = 15;
  drivefwdtime(20, 3);
  maxpower = 80;
  drivefwdtime(-20, 1);
  
  doubleturn(-10, 0.7);
  maxpower = 80;
  drivefwdtime(30, 1.3);
  startlift(400, true);
  doubleturn(85, 0.8);
  maxpower = 30;
  drivefwdtime(35, 2.5);
  //turn(40, 0.5);
  backmode = 3;
  drivefwd(4, 0.4);
  //turn(95, 0.5);
  */
}

void autoTask::upmogorush()
{
  maxpower = 120;
  fcmode = 1;
  drivefwdtime(51, 1);
  maxpower = 90;
  fcmode = 2;
  backmode = 1;
  drivefwd(-23, 15);
  /*
  turn(-88, 1);
  drivefwdtime(-20, 1);
  backmode = 2;
  startlift(400, false);
  drivefwdtime(6, 0.6);
  ringvelocity = 84;
  ringmode = 2;
  maxpower = 100;
  turn(-1, 1);
  maxpower = 20;
  drivefwdtime(44, 4);
  maxpower = 100;
  drivefwdtime(-50, 2);
  startlift(0, false);
  backmode = 3;
  */
}

void autoTask::fake()
{
  maxpower = 100;
  turn(-44, 0.3);
  fcmode = 1;
  maxpower = 120;
  drivefwdtime(61.5, 1.17);
  fcmode = 2;
  maxpower = 100;
  drivefwd(-32.5, 15);
  /*
  backmode = 3;
  turn(-89, 1);
  drivefwdtime(-32, 1.5);
  backmode = 2;
  startlift(300, false);
  drivefwdtime(6.5, 0.6);
  ringvelocity = 88;
  ringmode = 2;
  maxpower = 100;
  doubleturn(5, 1);
  maxpower = 20;
  drivefwdtime(44, 4);
  maxpower = 70;
  drivefwdtime(-50, 2);
  startlift(0, false);
  backmode = 3;
  */
}

void autoTask::middle()
{
  fcmode = 1;
  maxpower = 120;
  drivefwdtime(61.5, 1.17);
  fcmode = 2;
  maxpower = 100;
  drivefwd(-32.5, 15);
}

void autoTask::doublemogo()
{
  /*
  backmode = 3;
  wait(0.4, sec);
  drivefwdtime(-15, 0.85);
  fcmode = 1;
  backmode = 2;
  turn(30, 0.5);
  ringvelocity = 82;
  ringmode = 2;
  drivefwdtime(13, 0.7);
  turn(134, 1);
  maxpower = 120;
  drivefwdtime(70, 1.37);
  fcmode = 2;
  //drivefwdtime(-40, 1);
  turn(40, 0.7);
  startlift(320, false);
  //wait(0.3, sec);
  maxpower = 33.3;
  drivefwd(50, 3);
  //rings
  startlift(0, false);
  maxpower = 80;
  turn(90, 0.4);
  drivefwd(12, 0.5);
  fcmode = 1;
  drivefwdtime(-12, 0.5);
  startlift(500, false);
  turn(45, 0.4);
  backmode = 3;
  drivefwdtime(22, 1.2);
  //startlift(0, false);
  wait(0.2, sec);
  turn(110, 0.6);
  fcmode = 1;
  drivefwdtime(-17, 0.8);
  backmode = 2;
  startlift(550, false);
  turn(80, 0.3);
  maxpower = 20;
  drivefwd(20, 1.5);
  backmode = 3;
  */
  maxpower = 120;
  fcmode = 1;
  drivefwdtime(51, 1);
  maxpower = 90;
  fcmode = 2;
  backmode = 1;
  drivefwd(-23, 15);
  startlift(100, false);
  maxpower = 100;
  turn(130, 1);
  fcmode = 1;
  backmode = 3;
  maxpower = 120;
  drivefwdtime(-62, 1.17);
  backmode = 2;
  maxpower = 100;
  wait(0.3, sec);
  drivefwd(32.5, 15);
}
void autoTask::mainauto()
{
  ytrack.resetRotation();
  xtrack.resetRotation();
  switch(automode)
  {
    case 1: //testing
    testing();
    break;
    case 2: //skills
    fake();
    break;
    case 3:
    downmogorush();
    break;
    case 4:
    upmogorush();
    break;
    case 5:
    middle();
    break;
    case 6: 
    doublemogo();
    break;


  }
}
