#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor fl = motor(PORT8, ratio18_1, false);
motor fr = motor(PORT3, ratio18_1, true);
motor bl = motor(PORT9, ratio18_1, false);
motor br = motor(PORT2, ratio18_1, true);
pneumatics fc = pneumatics(Brain.ThreeWirePort.E); 
motor fb = motor(PORT6, ratio36_1, false);
motor bml = motor(PORT7, ratio36_1, true);
motor bmr = motor(PORT5, ratio36_1, false);
inertial in = inertial(PORT4);
pneumatics bc = pneumatics(Brain.ThreeWirePort.A);
bumper bm = bumper(Brain.ThreeWirePort.H);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}