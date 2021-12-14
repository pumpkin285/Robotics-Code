#include "vex.h"
#include "../../include/definitions/tasks.h"

void autoTasks::testing()
{
  //backmogomove(100, -250);
  //fourbarmove(100, 600);
  //drivedoublemogo(25, 80, 1, 1.5);
  gyroturn(90, 80, 1, 1);
  //drive(36, 80, 1, 2.4);
}

void autoTasks::upauto()
{
  frontclawmove(false, 0.1);
  drive(50, 100, 1, 1.45);
  frontclawmove(true, 0.1);
  drivebackmogo(25, 100, 2, 1.3, 20, -400, 100);
  gyroturnback(-83, 80, 2, 0.6, -400, 100);
  drivebackmogo(15, 85, 2, 0.8, 26, -520, 100);
  backmogomove(100, -430);
  gyroturn(-32, 80, 1, 0.6);
  backmogomove(100, -490);
  //frontclawmove(false, 0.1);
  drive(10, 90, 1, 0.5);
  //drive(7, 80, 1, 0.4);
  gyroturn(120, 80, 1, 1);
  drivebackmogo(43, 80, 2, 2.4, 43, -505, 100);
  backmogomove(30, -400);
  gyroturn(140, 80, 2, 0.4);
  drive(50, 100, 1, 2.5);
}

void autoTasks::downauto()
{
  /*
  //gyroturn(3, 80, 1, 0.4);
  drivebackmogo(49, 100, 2, 1.65, 52, -470, 100);
  backmogomove(100, -300);
  drive(30, 80, 1, 1.8);
  gyroturn(-40, 60, 2, 1);
  fourbarmove(100, 250);
  drive(9, 80, 1, 0.6);
  frontclawmove(false, 0.5);
  drive(9, 80, 2, 0.7);
  gyroturn(-132, 80, 2, 1);
  //backmogomove(100, -520);
  */
  frontclawmove(false, 0.001);
  drive(45, 100, 1, 1.35);
  frontclawmove(true, 0.1);
  drivefrontmogo(29, 100, 2, 1.4, 10, -50, 100);
  frontclawmove(false, 0.1);
  drive(11, 80, 2, 0.7);
  gyroturn(40, 80, 1, 0.5);
  drive(10, 80, 2, 0.6);
  gyroturnback(-86, 80, 2, 0.8, -510, 100);
  drive(16.5, 80, 2, 0.8);
  drive(22.5, 80, 1, 1.2);
  backmogobutton(100);
  /*
  drive(10, 80, 2, 0.6);
  gyroturn(30, 80, 1, 0.8);
  drive(60, 100, 1, 1.8);
  frontclawmove(true, 0.1);
  drive(30, 80, 2, 1.5);
  */
  
  gyroturn(-118, 80, 2, 0.5);
  drive(43, 100, 2, 1.6);
  gyroturn(16, 80, 1, 0.8);
  //drive(25, 80, 1, 1.5);
  
  //frontclawmove(true, 0.1);
}

void autoTasks::skills()
{
  backmogomove(100, -510);
  drive(18, 80, 2, 1);
  backmogobutton(100);
  bml.resetPosition();
  bmr.resetPosition();
  //drive(2, 80, 1, 0.6);
  gyroturn(92, 80, 1, 1);
  frontclawmove(false, 0.1);
  drivebackmogo(48, 80, 1, 2.4, 48, -200, 100);
  frontclawmove(true, 0.2);
  gyroturn(115, 80, 1, 0.6);
  fourbarmove(100, 300);
  drivefrontmogo(54, 80, 1, 2.5, 54, 750, 100);
  gyroturn(117, 80, 1, 0.2);
  fourbarmove(80, 520);
  wait(0.3, sec);
  frontclawmove(false, 0.3);
  //platform done
  drive(3, 40, 2, 0.3);
  gyroturn(4, 80, 2, 0.8);
  mogoreset(-30, -520);
  drive(34, 80, 1, 1.8);
  backmogomove(100, -530);
  frontclawmove(true, 0.2);
  drive(18, 80, 2, 1);
  gyroturnmogo(45, 80, 1, 1);
  drive(55, 70, 2, 2.7);
  backmogomove(20, -400);
  //slow tall mogo lift (yes it always messes up here :|)
  gyroturn(0, 80, 2, 0.5);
  gyroturn(53, 80, 1, 0.5);
  drive(52, 80, 2, 2.7);
  backmogomove(70, -520);
  drive(15, 80, 1, 0.8);
  gyroturn(0, 80, 2, 0.7);
  drive(22, 80, 2, 1.2);
  backmogomove(100, -20);
  gyroturn(10, 80, 1, 0.2);
  drivefrontmogo(38, 80, 1, 2.1, 50, 740, 100);
  gyroturn(-65, 80, 2, 1);
  drivefrontmogo(12, 80, 1, 0.7, 10, 700, 100);
  fourbarmove(100, 500);
  frontclawmove(false, 0.3);
  //second platform done
  drivefrontmogo(20, 80, 2, 1, 10, 0, 100);
  gyroturn(131, 80, 1, 1);
  fourbarmove(100, 0);
  drive(22, 80, 1, 1.2);
  frontclawmove(true, 0.2);
  gyroturnmogo(74, 80, 2, 0.7);
  fourbarmove(100, 200);
  drivefrontmogo(50, 80, 1, 2.7, 50, 750, 100);
  fourbarmove(100, 750);
  //drivefrontmogo(21, 70, 1, 1.4, 20, 750, 100);
  fourbarmove(100, 550);
  frontclawmove(false, 0.2);
   //first platform again
  drivefrontmogo(5, 80, 2, 0.5, 5, 650, 100);
  gyroturn(0, 80, 2, 1);
  //fourbarmove(100, 0);
  drivefrontmogo(31, 80, 2, 1.8, 31, -40, 100);
  gyroturn(47, 80, 1, 0.7);
  drive(21, 80, 1, 1.1);
  frontclawmove(true, 0.2);
  drive(12, 80, 2, 0.7);
  gyroturn(-76, 80, 2, 1);
  backmogomove(100, -300);
  drivebackmogo(78, 100, 1, 2.8, 80, -520, 100);
  //gyroturn(0, 80, 1, 0.7);
  //drivefrontmogo(10, 80, 1, 0.4, 10, 700, 100);
  /*
  fourbarmove(100, 700);
  gyroturn(-60, 80, 1, 0.4);
  drive(5, 80, 1, 0.3);
  frontclawmove(false, 0.1);
  drive(30, 80, 2, 1);
  */
  /*
  drive(10, 80, 1, 1);
  backmogomove(100, -510);
  gyroturn(-40, 80, 2, 1);
  drive(20, 80, 1, 1.5);
  clawmove(100, 0, 2);
  */
}

void autoTasks::awpauto()
{
  fourbarmove(100, 270);
  drive(10.5, 90, 1, 0.9);
  frontclawmove(false, 0.1);
  drive(8, 80, 2, 0.7);
  fourbarmove(100, 0);
  gyroturn(89, 80, 1, 0.6);
  drive(18.3, 80, 2, 1.4);
  gyroturn(177.7, 80, 1, 1);
  drivebackmogo(102, 85, 2, 3.8, 60, -510, 100);
  //gyroturn(172, 80, 2, 0.3);
  //drive(23, 80, 2, 1.2);
  backmogomove(100, -300);
  drive(28, 80, 1, 1.4);
  gyroturnback(232, 80, 1, 0.6, -490, 100);
  //backmogomove(100, -480);
  
  drive(34, 100, 1, 1.4);
  frontclawmove(true, 0.1);
  backmogomove(100, -450);
  drive(32, 100, 2, 1);
}

void autoTasks::middleauto()
{
  backclawmove(false, 0.1);
  drive(60, 100, 2, 2.8);

}
void autoTasks::mainauto(int automode)
{
  //calibrate();
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
  Brain.Screen.print("done");
  switch(automode)
  {
    case 1:
    drivereset();
    testing();
    break;
    case 2:
    drivereset();
    upauto();
    break;
    case 3:
    drivereset();
    downauto();
    break;
    case 4:
    drivereset();
    skills();
    break;
    case 5:
    drivereset();
    awpauto();
    break;
    case 6:
    drivereset();
    middleauto();
    break;
    default: 
    wait(10, msec);
    break;
  }
  
}
