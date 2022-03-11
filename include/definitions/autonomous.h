#ifndef autonomous_h
#define autonomous_h

#define drivedelay 45
#define turndelay 45

extern int direction, directionconst;
extern int automode, driveexit;
extern int ringmode, fbmode, fcmode, backmode, drivemode;
extern double fbtarget, fbvelocity, conveyorvelocity;
extern double setpointdeg, starttime, currenttime, timecount, accel, maxaccel, leftavg, rightavg;
extern double leftwheelpower, leftactualwheelpower, rightwheelpower, rightactualwheelpower;
extern double goal, previousheading, currentheading, maxpower;
extern int loopnumber;
extern double lefterror[drivedelay], righterror[drivedelay], headingerror[turndelay];


class autonTasks{
public:

  static void drive();

  static void drivefwd(double distance, int direction, double time);

  static void drivehold(double distance, int direction, double errormargin, double time);

  static void gyroturn();

  static void turn(double degrees, int direction, double time);

  static void curveturn(double curveratio, double degrees, int direction, double time);

  static void drivelift(double distance, int direction, double fbdeg, double fbtime, double time);

  static void driveback(double distance, int direction, double bctime, double time);

  static void turnlift(double degrees, int direction, double fbdeg, double fbtime, double time);

  static void drivestop();

  static void drivereset();

  static void driving();

  static void front();

  static void back();

  static void ring();

  static double motorpower(double currenterror, double previouserror, float kP, float kD);

  static double min(double value1, double value2, double value3);

  static void mainauton();

  static void test();

  static void awpauto();

  static void upauto();

  static void downauto();

  static void skills();

  static void calibrate();

  static void collectring(double distance, int direction, bool conveyoroff, double time);

  static void backclamp();
  
  static void backrelease();

  static void frontclamp();

  static void frontrelease();

  static void lift(double deg, double waittime, bool waitfinish);
};

#endif