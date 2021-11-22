#ifndef tasks_hpp
#define tasks_hpp

#define drivedelay 45
#define turndelay 45



extern double start, end;
extern double leftpower, rightpower, fwpow, turnpow, backmogoposition, frontclawposition, fourbarposition;
extern double forward, turning, leftpower, rightpower;
extern double fourbarposition, frontclawposition, backmogoposition;
extern double rightx, righty;
extern int l1, l2;
extern bool a, b, r1, r2;
extern double setpointdeg, starttime, currenttime, timecount, accel, maxaccel, leftavg, rightavg;
extern double leftwheelpower, leftactualwheelpower, rightwheelpower, rightactualwheelpower;
extern double goal, previousheading, currentheading;
extern int directionconst, loopexit, loopnumber;
extern double lefterror[drivedelay], righterror[drivedelay], headingerror[turndelay];
class driverTasks {
public:
  static void chassis(double fw, double turn, bool hold, bool unhold);

  static void frontmogo(double fourbar, bool clawup, bool clawdown);

  static void backmogo(bool backup, bool backdown);

  static void driving();

  static void front();

  static void back();

  static void setbrake();

  static void setbackclaw();
};

class autoTasks {
public:
  void drive(double distance, double maxvelocity, int direction, double maxtime);

  void drivebackmogo(double distance, double maxvelocity, int direction, double maxtime, double startbackmogo, double backmogovalue, double backmogovelocity);

  void gyroturn(double targetangle, double maxvelocity, int direction, double maxtime);

  void gyroturnback(double targetangle, double maxvelocity, int direction, double maxtime, double backmogovalue, double backmogovelocity);

  void frontmogopick();

  void frontmogolift();

  void backmogopick();

  void backmogorelease();

  void mainauto(int automode);

  void drivereset();

  double motorpower(double currenterror, double previouserror, float kP, float kD);

  double min(double value1, double value2, double value3);

  void drivestop();

  void testing();

  void upauto();

  void downauto();

  void awpauto();

  void skills();
  
  void calibrate();

  void backmogomove(double speed, double todegree);

  void fourbarmove(double speed, double todegree);

  void frontclawmove(bool fc, double time);

  void backclawmove(bool bc, double time);

  void backmogobutton(double speed);
};

#endif
