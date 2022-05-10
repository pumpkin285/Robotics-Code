//file for conveyor subsystem  during autonomous

#include "vex.h"
#include "robot-config.h"
#include "definitions/autonomous.h"
#include "math.h"


int ringmode, ringloop;
double ringpos[jamduration], ringvelocity;
//ringpos[]: lower index is newer values, index 0 is the current value of the conveyor encoder
double ringsensitivity = 0.5; 
//the ring sensitivity sets the threshold for the conveyor to be detected as "jammed"
//for example, a sensitivity of 0.6 would be that the conveyor has to go under 60% of normal velocity to be jammed
bool conveyoron;

void autoTask::intaking()
{
  ringloop = 0;
  resetringvalue();
  while(true)
  { 
    
    //setringmode(setring);
    switch(ringmode)
    {
      case 1: //conveyor stop
      conveyor.stop();
      break;
      case 2: //conveyor goes up
      conveyor.spin(fwd, ringvelocity, pct);
      break;
      case 3: //conveyor goes up by 2 seconds then reset to up
      conveyor.spin(reverse, 30, pct);
      break;
      default:
      wait(10, msec);
      break;

    }
    wait(10, msec);
    ringloop ++;
  }
}

void autoTask::setringmode(bool setconveyor)
{
  if(setconveyor)
  {
  //update the encoder values
    for(int i = jamduration - 1; i > 0; i--)
    {
      ringpos[i] = ringpos[i-1];
    }
    ringpos[0] = conveyor.position(deg);
    
    if(!conveyoron)
    {
      ringmode = 1;
    }
    else 
    { 
      ringvelocity = (ringpos[0] - ringpos[jamduration / 2]) / (ringpos[jamduration / 2] - ringpos[jamduration-1] + 0.1);
      //the line above finds the relative ratio of the ring velocity at first half compared to second half of array
      //plus 0.1 at the end to avoid dividing by 0
      if(ringmode == 2)
      {
        if(ringvelocity < ringsensitivity && ringloop > 10)
        {
          ringmode = 3;
          ringloop = 0; // ringloop resets each time it changes ringmode
        }
      }
      else if(ringmode == 3)
      {
        if(ringloop > 100)
        {
          ringmode = 2;
          resetringvalue();
          ringloop = 0;
        }
      }
    }
  }
}

void autoTask::resetringvalue()
{
  //resets the entire array to 0 in order to avoid the conveyor going down right at the start
  for(int i = 0; i < jamduration; i++)
  {
    ringpos[i] = 0;
  }
}