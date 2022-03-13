#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"

int automode;

void autonTasks::test()
{
  drivefwd(55, 1, 1.1);
}

void autonTasks::awpauto()
//one ring in non awp, grabs the tall mogo, two rings in awp line mogo
{
  backmode = 1;
  lift(200, 0.3, false);
  drivefwd(7, 1, 0.6);
  frontrelease();
  wait(0.3, sec);
  drivelift(10, 2, -10, 0.2, 0.6);
  turn(90, 1, 0.6);
  drivefwd(19, 2, 1.4);
  turn(183, 1, 0.6);
  drivefwd(78, 2, 2.7);
  turn(230, 1, 0.4);
  drivefwd(42, 1, 1.5);
  frontclamp();
  drivefwd(44, 2, 1.3);
  turn(179.5, 2, 0.4);
  drivefwd(26, 2, 1.2);
  lift(100, 0, false);
  backclamp();
  ringmode = 2;
  drivefwd(15, 1, 0.7); 
  turn(225, 1, 0.4);
  backrelease();
  /*
  drivefwd(10, 1, 0.6);
  turn(216, 1, 0.4);
  drivefwd(48, 1, 2.2);
  ringmode = 1;
  frontclamp();
  drivefwd(50, 2, 2.4);
  */
}

void autonTasks::downauto()
//rush middle mogo, grabs non awp mogo, intakes rings
{
  fcmode = 1;
  drivefwd(55, 1, 1.2);
  fcmode = 2;
  wait(0.05, sec);
  drivelift(30, 2, 200, 0, 2.5);
  lift(-60, 1, false);
  frontrelease();
  
  turn(30, 1, 0.4);
  drivelift(21, 2, 100, 0.3, 1);
  backrelease();
  
  turn(-95, 2, 0.7);
  drivefwd(22, 2, 1.2);
  //wait(2, sec);
  backclamp();
  //turn(-110, 2, 0.3);
  ringmode = 2;
  maxpower = 25;
  drivefwd(19, 1, 2.7);
  maxpower = 200;
  drivefwd(6, 2, 0.4);
  turn(40, 1, 0.7);
  backrelease();
  drivefwd(8, 1, 0.5);
  turn(30, 2, 0.2);
}

void autonTasks::upauto()
//rush middle mogo, grabs awp mogo, then intakes rings in the row
{
  fcmode = 1;
  drivefwd(54, 1, 1.1);
  fcmode = 2;
  turn(5, 1, 0.05);
  wait(0.1, sec);
  drivefwd(27, 2, 2.4);
  //lift(0, 0, false);
  turn(-105, 2, 0.8);
  drivefwd(19, 2, 1.3);
  backclamp();
  ringmode = 2;
  conveyorvelocity = 80;
  lift(250, 0.1, false);
  drivefwd(6, 1, 0.4);
  turn(0, 1, 0.9);
  maxpower = 30;
  
  conveyorvelocity = 80;
  drivefwd(33, 1, 4);
  maxpower = 100;
  drivelift(38, 2, 50, 0.3, 2.4);
  //wait(1, sec);
  backrelease();
  drivefwd(3, 1, 1);
}

void autonTasks::skills()
{
  //start red side
  //grabs blue non awp and middle mogo, scores middle to blue platform
  backmode = 1;
  wait(0.8, sec);
  drivefwd(5, 2, 0.4);
  backclamp();
  turn(30, 1, 0.4);
  drivefwd(10, 1, 0.7);
  frontrelease();
  turn(100, 1, 0.7);
  drivefwd(48, 1, 2.3);
  frontclamp();
  lift(700, 0.3, false);
  turn(115, 1, 0.5);
  drivefwd(49, 1, 2.3);
  lift(550, 0, true);
  drivefwd(6, 1, 0.5);
  frontrelease();
  //first platform done
  //turns, drop blue mogo, grab red awp with front, back up with tall mogo, grab blue awp with back, put red on platform
  //lift(530, 0, true);
  drivefwd(12.5, 2, 0.5);
  turnlift(2.5, 2, -10, 0.3, 0.7);
  backmode = 3;
  wait(0.2, sec);
  drivefwd(35, 1, 2);
  frontclamp();
  wait(0.2, sec);
  lift(40, 0, false);
  drivefwd(20, 2, 1.2);
  turn(51, 1, 0.7);
  drivefwd(42, 2, 2.1);
  backclamp();  
  wait(0.2, sec);
  //tall mogo
  maxpower = 70;
  turn(0, 2, 0.7);
  turn(51, 1, 1);
  maxpower = 200;
  drivefwd(72, 2, 3.1);
  backrelease();
  wait(0.4, sec);
  drivefwd(30.5, 1, 1);
  turn(0, 2, 0.6);
  drivefwd(21.5, 2, 1);
  backclamp();
  drivelift(47.5, 1, 700, 0, 2.3);
  turn(-65, 2, 0.6);
  lift(550, 0, false);
  drivefwd(7, 1, 0.5);
  frontrelease();
  //second platform
  //turns, grab remaining middle mogo, score on platform, grab the first blue, score on platform
  drivefwd(11, 2, 0.7);
  lift(-10, 0, false);
  turn(-226, 2, 0.9);
  drivefwd(40, 1, 1.9);
  frontclamp();
  lift(700, 0, false);
  turn(-290, 2, 0.7);
  drivefwd(49, 1, 2);
  lift(600, 0, true);
  turn(-320, 2, 0.3);
  drivefwd(5, 1, 0.4);
  frontrelease();
  drivefwd(7, 2, 0.5);
  lift(-10, 0, false);
  turn(-340, 2, 0.5);
  lift(-10, 0, true);
  drivefwd(27, 1, 1);
  frontclamp();
  drivefwd(10, 2, 0.4);
  lift(700, 0.9, true);
  turn(-280, 1, 0.7);
  frontrelease();
  //first platform again
  //turn, drop the blue mogo on the back, grab red under blue platform, go back to red side 
  turn(-360, 2, 0.8);
  lift(-10, 0.3, false);
  drivefwd(56, 2, 1.6);
  turn(-320, 2, 0.5);
  drivefwd(15, 1, 0.8);
  frontclamp();
  drivefwd(15, 2, 0.8);
  turn(-435, 2, 0.8);
  backmode = 3;
  wait(0.2, sec);
  drivefwd(90, 1, 5);
}

void autonTasks::mainauton()
{
  switch(automode)
  {
    case 1: 
    test();
    break;
    case 2: 
    awpauto();
    break;
    case 3:
    downauto();
    break;
    case 4:
    upauto();
    break;
    case 5:
    skills();
    break;
  }
}
