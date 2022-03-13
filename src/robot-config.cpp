#include "vex.h"

using namespace vex;
<<<<<<< HEAD

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller Controller1 = controller(primary);
motor fl = motor(PORT9, ratio18_1, true);
motor ml = motor(PORT5, ratio18_1, true);
motor bl = motor(PORT3, ratio18_1, true);
motor fr = motor(PORT15, ratio18_1, false);
motor mr = motor(PORT12, ratio18_1, false);
motor br = motor(PORT4, ratio18_1, false);
motor fb = motor(PORT8, ratio36_1, true);  
motor conveyor = motor(PORT20, ratio6_1, false);
pneumatics fc = pneumatics(Brain.ThreeWirePort.G);
pneumatics backlift = pneumatics(Brain.ThreeWirePort.D);
pneumatics bc = pneumatics(Brain.ThreeWirePort.A);
inertial in = inertial(PORT7);
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
=======
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
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
}