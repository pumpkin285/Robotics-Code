#ifndef autonomous_h
#define autonomous_h
#define jamduration 100 
#define drivedelay 45
#define turndelay 45
#define turndelaytime 10
#define driveerror 20
#define turnerror 0.6

extern int fbmode, fcmode, backmode, drivemode, ringmode, automode, loopnumber, directionconst;
extern double fbgoal, fbvelocity, ringvelocity, ringpos[jamduration];
extern double leftwheelpower, leftpurewheelpower, leftactualwheelpower, rightwheelpower, rightpurewheelpower, rightactualwheelpower;
extern double startx, starty, goalx, goaly, goalheading, goaldistance, finalgoaldistance, prevfinalgoaldistance;
extern double headingerror[turndelay], lefterror[drivedelay], righterror[drivedelay];
extern double cbezpoint[10][2], qbezpoint[10][2], curvature, trackwidth, targetvelocity;
extern double c1x, c1y, c2x, c2y, q1x, q1y, t, point, lookaheadx, lookaheady, offsetheading, lookaheadheading, lookaheaddistance, lookaheadhdis;
extern double accel, maxaccel, maxpower, starttime, currenttime, timecount, accel, maxaccel, setpointdeg, goal, startenc, endenc;
extern bool conveyoron, loopexit, setring, purepid;

class autoTask {
  public: 
  static void mainauto();

  static void driving();

  static void intaking();

  static void setringmode(bool set);

  static void resetringvalue();

  static void frontclaw();

  static void fourbar();

  static void back();

  static void gyroturn();

  static void drive();

  static void twomogoturn();

  static void setlookahead();

  static void drivefwdtime(double distance, double time);

  static void drivefwd(double distance, double time);

  static void turntopoint(double endx, double endy, double time);

  static void turn(double goalheading, double time);

  static void doubleturn(double goalheading, double time);

  static double calcheading(double startx, double starty, double endx, double endy);

  static void startlift(double liftgoal, bool finish);

  static double motorpower(double currenterror, double previouserror, float kP, float kD);

  static double min(double value1, double value2, double value3);


  static void drivestop();

  static void testing();

  static void fake();

  static void downmogorush();

  static void upmogorush();

  static void middle();
  
  static void doublemogo();
};

class pure {
  public:

  static void cpathgen();

  static void qpathgen();

  static void bezpathfollow(); 

  static void cubic(double c1x, double c1y, double c2x, double c2y, double goalx, double goaly, bool startaccel, bool endstop);

  static void quadratic(double q1x, double q1y, double goalx, double goaly, bool startaccel, bool endstop);
};

#endif