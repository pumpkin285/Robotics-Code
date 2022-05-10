//file for position tracking during autonomous

#include "vex.h"
#include "definitions/init.h"
#include "robot-config.h"
#include "math.h"

double xtrackdis = 0.3317; //the distance from the back tracking wheel line to the tracking center
double ytrackdis = 1.587; //the distance from the right tracking wheel line to the tracking center
double xwheel, ywheel, heading, headingdeg; //encoder values for the tracking wheels and inertials
double prevxwheel, prevywheel, prevheading;
double xtrackmove, ytrackmove, headingdiff;
double arcradius, trackradius, endcenterdis, endcenterdisx, endcenterdisy;
double deltax, deltay, xchange, ychange, currentx, currenty;
/*
  delta R = ytrackmove
  delta S = xtrackmove
  delta theta = headingdiff
  ED = trackradius
  AD = arcradius
  CD = endcenterdis
  x component of AC without offset = deltax
  y component of AC without offset = deltay
  x component of AC with offset = xchange
  y components of AC with offset = ychange
*/

void positiontrack::updatesensor()
{
  //update previous sensor values
  prevxwheel = xwheel;
  prevywheel = ywheel;
  prevheading = heading;
  //update current sensor values
  xwheel = xtrack.position(deg) * 2.8 * M_PI / 360; //convert degrees to inches, 2.75 inch wheels
  ywheel = -ytrack.position(deg) * 2.8 * M_PI / 360; //the y tracking wheel is reversed, hence negative
  heading = in2.rotation(deg) * M_PI / 180; //average out the headings of the two inertials, change deg to rad
  headingdeg = in2.rotation(deg);
  //4/15/2022: left inertial very off, swapped out
}

//calculates the change in x and y coordinates
void positiontrack::calcposdiff() //see photos in robotics/photos/odom
{
  /*
  delta R = ytrackmove
  delta S = xtrackmove
  delta theta = headingdiff
  ED = trackradius
  AD = arcradius
  CD = endcenterdis
  x component of AC without offset = deltax
  y component of AC without offset = deltay
  x component of AC with offset = xchange
  y components of AC with offset = ychange
  */
  /*
  //calculates change in sensors
  xtrackmove = xwheel - prevxwheel;
  ytrackmove = ywheel - prevywheel;
  headingdiff = (heading - prevheading);
  if(fabs(headingdiff) < 0.000001)
  {
    headingdiff = 999999; //to avoid dividing by 0
  }
  //finds the arc radius, then CD, and components of CD
  trackradius = ytrackmove / headingdiff;
  if(ytrackmove != 0 && headingdiff != 999999)
  {
    arcradius = trackradius + ytrackdis;
  }
  else 
  {
    arcradius = 0;
  }
  if((ytrackmove > 0 && headingdiff > 0) || (ytrackmove < 0 && headingdiff < 0))
  {
    endcenterdis = arcradius - xtrackmove;
    endcenterdisx = endcenterdis * -cos(headingdiff);  
  }
  else 
  {
    endcenterdis = fabs(arcradius) + xtrackmove;
    endcenterdisx = endcenterdis * cos(headingdiff);
  }
  if(ytrackmove > 0)
  {
    endcenterdisy = endcenterdis * fabs(sin(headingdiff)); //if delta theta is negative then endcenterdisy would also be negative
  }
  else 
  {
    endcenterdisy = endcenterdis * -fabs(sin(headingdiff));
  }
  

  //calculate components of AC
  deltax = arcradius + endcenterdisx;
  deltay = endcenterdisy;
  //calculate x coordinate and y coordinate changes
  xchange = cos(prevheading) * deltax + sin(prevheading) * deltay;
  ychange = -sin(prevheading) * deltax + cos(prevheading) * deltay;
  */
  //4/15/2022: that algorithm above does not account for the back tracking wheel during arc
  //below is using 5225a document
  xtrackmove = xwheel - prevxwheel;
  ytrackmove = ywheel - prevywheel;
  headingdiff = (heading - prevheading);
  /*
  if(fabs(headingdiff) < 0.008)
  {
    headingdiff = 999999;
  }
  if((ytrackmove > 0 && headingdiff > 0) || (ytrackmove < 0 && headingdiff < 0))
  {
    deltax = 2 * sin(headingdiff / 2) * (xtrackmove / headingdiff + xtrackdis);
    deltay = 2 * sin(headingdiff / 2) * (ytrackmove / headingdiff + ytrackdis);
  }
  else 
  {
    deltax = 2 * sin(headingdiff / 2) * (xtrackmove / headingdiff - xtrackdis);
    deltay = 2 * sin(headingdiff / 2) * (ytrackmove / headingdiff - ytrackdis);
  }
  if(headingdiff == 999999)
  {
    deltax = xtrackmove;
    deltay = ytrackmove;
  }
  */
  if(headingdiff != 0)
  {
    if((ytrackmove > 0 && headingdiff > 0) || (ytrackmove < 0 && headingdiff < 0))
    {
      deltax = 2 * sin(headingdiff / 2) * (xtrackmove / headingdiff + xtrackdis);
      deltay = 2 * sin(headingdiff / 2) * (ytrackmove / headingdiff + ytrackdis);
    }
    else 
    {
      deltax = 2 * sin(headingdiff / 2) * (xtrackmove / headingdiff + xtrackdis);
      deltay = 2 * sin(headingdiff / 2) * (ytrackmove / headingdiff + ytrackdis);
    }
  }
  else 
  {
    deltax = xtrackmove;
    deltay = ytrackmove;
  }
  xchange = cos(prevheading) * deltax + sin(prevheading) * deltay;
  ychange = -sin(prevheading) * deltax + cos(prevheading) * deltay;
}

void positiontrack::globalposition()
{
  currentx = 0;
  currenty = 0;
  while(true)
  {
    updatesensor();
    calcposdiff();
    currentx += xchange;
    currenty += ychange;
    wait(5, msec);
  }
}

