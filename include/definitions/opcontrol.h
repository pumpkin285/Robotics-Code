#ifndef opcontrol_h
#define opcontrol_h

extern double leftx, lefty, righty, speedconst;
extern bool l1, l2, r1, r2, a, b, x, y, rarrow, uarrow;
extern int holdno, conveyorno;

class driveTask{
public:
  static void ringthread();

  static void clawthread();

  static void drivethread();

  static void fourbarthread();

  static void ring(bool up, bool down);

  static void frontmogo(bool frontclaw, bool frontrelease);

  static void backmogo(bool backclaw, bool backrelease, bool endrelease, bool liftback);

  static void drive(double fwd, double turn);

  static void setdrivespeed(bool slow);

  static void stophold(bool hold);

  static void fourbar(double fbvelocity);
};

#endif