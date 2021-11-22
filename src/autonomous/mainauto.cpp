#include "vex.h"
#include "../../include/definitions/tasks.h"

void autoTasks::testing()
{
  drive(25, 100, 1, 1.5);
  //gyroturn(90, 80, 1, 2);
}

void autoTasks::upauto()
{
  frontclawmove(false, 0.1);
  drive(48, 100, 1, 1.5);
  frontclawmove(true, 0.3);
  gyroturnback(-38, 80, 2, 0.6, -485, 100);
  drivebackmogo(26, 100, 2, 1.2, 26, -485, 100);
  backmogomove(100, -300);
  gyroturn(30, 80, 1, 1);
  drive(20, 90, 2, 1);
  backmogomove(100, -485);
  drive(10, 80, 1, 0.8);
  gyroturn(120, 80, 1, 1);
}

void autoTasks::downauto()
{
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
  
}

void autoTasks::skills()
{
  backmogomove(100, -475);
  drive(18, 80, 2, 1);
  backmogobutton(100);
  drive(2, 80, 1, 0.6);
  gyroturn(94, 80, 1, 1);
  frontclawmove(false, 0.1);
  drive(49, 80, 1, 2.4);
  frontclawmove(true, 0.2);
  gyroturn(117, 80, 1, 1);
  fourbarmove(100, 650);
  drive(54, 60, 1, 3.5);
  fourbarmove(100, 550);
  frontclawmove(false, 0.5);
  //platform done
  drive(6, 40, 2, 0.3);
  gyroturn(0, 80, 2, 1);
  fourbarmove(100, 0);
  backmogomove(100, -475);
  drive(34, 80, 1, 2);
  frontclawmove(true, 0.5);
  gyroturn(37, 80, 1, 1);
  drive(57, 80, 2, 2.6);
  backmogomove(100, -310);
  gyroturn(45, 80, 1, 0.5);
  drive(60, 80, 2, 3);
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
  fourbarmove(100, 280);
  drive(10.5, 90, 1, 0.9);
  frontclawmove(false, 0.1);
  drive(8, 80, 2, 0.7);
  fourbarmove(100, 0);
  gyroturn(89, 80, 1, 0.6);
  drive(18.3, 80, 2, 1.4);
  gyroturn(176.7, 80, 1, 1);
  drivebackmogo(102, 85, 2, 3.8, 60, -475, 100);
  //gyroturn(172, 80, 2, 0.3);
  //drive(23, 80, 2, 1.2);
  backmogomove(100, -300);
  drive(28, 80, 1, 1.4);
  gyroturn(232, 80, 1, 0.6);
  backmogomove(100, -480);
  
  drive(32, 100, 1, 1.4);
  frontclawmove(true, 0.1);

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
    default: 
    wait(10, msec);
    break;
  }
  
}
