#ifndef init_h
#define init_h

void resetposition();

void calibrate();

void printscreen();

void setbrake();

extern double xtrackdis, ytrackdis;
extern double xwheel, ywheel, heading, headingdeg, prevxwheel, prevywheel, prevheading;
extern double xtrackmove, ytrackmove, headingdiff;
extern double arcradius, trackradius, endcenterdis, endcenterdisx, endcenterdisy;
extern double deltax, deltay, xchange, ychange, currentx, currenty;


class positiontrack{
  public:
  static void globalposition();

  static void calcposdiff();

  static void updatesensor();
};



#endif