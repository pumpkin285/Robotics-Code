#include "vex.h"

using namespace vex;

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
}