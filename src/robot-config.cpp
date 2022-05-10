#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

controller Controller1 = controller(primary);
motor fl = motor(PORT7, ratio18_1, true);
motor ml = motor(PORT6, ratio18_1, false);
motor bl = motor(PORT5, ratio18_1, true);
motor fr = motor(PORT4, ratio18_1, false);
motor mr = motor(PORT3, ratio18_1, true);
motor br = motor(PORT2, ratio18_1, false);
motor fb = motor(PORT8, ratio36_1, true);
motor conveyor = motor(PORT20, ratio6_1, false);
pneumatics fc = pneumatics(Brain.ThreeWirePort.G);
pneumatics backlift = pneumatics(Brain.ThreeWirePort.B);
pneumatics bc = pneumatics(Brain.ThreeWirePort.A);
inertial in1j = inertial(PORT19);
inertial in2 = inertial(PORT9);
encoder xtrack = encoder(Brain.ThreeWirePort.E);
encoder ytrack = encoder(Brain.ThreeWirePort.C);

void vexcodeInit(void) {

}