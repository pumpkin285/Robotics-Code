#ifndef opcontrol_h
#define opcontrol_h

extern double leftx, lefty, rightx, righty;
extern int holdno, mogono;  
extern bool a, b, previousl1, currentl1, l2, r1, r2, previousx, currentx, y;
extern bool right1[6];
extern bool right2[6];

class driverTasks {
public: 
  static void chassis(double fw, double turn, bool hold, bool previoushold);

  static void frontlift(double fourbar);

  static void mogo(bool backup, bool backdown, bool frontup, bool frontdown, bool release);

  static void rings(bool previousintake, bool currentintake, bool outtake);

  static void driving();

  static void front();

  static void back();

  static void ring();
};
#endif