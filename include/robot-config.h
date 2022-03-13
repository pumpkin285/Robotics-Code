using namespace vex;

extern brain Brain;

<<<<<<< HEAD
extern controller Controller1;
extern motor fl;
extern motor ml;
extern motor bl;
extern motor fr;
extern motor mr;
extern motor br;
extern motor fb;
extern motor conveyor;
extern pneumatics fc;
extern pneumatics backlift;
extern pneumatics bc;
extern inertial in;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
=======
// VEXcode devices
extern controller Controller1;
extern motor fl;
extern motor fr;
extern motor bl;
extern motor br;
extern pneumatics fc;
extern motor fb;
extern motor bml;
extern motor bmr;
extern inertial in;
extern pneumatics bc;
extern bumper bm;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
>>>>>>> 69eb830d52cb4eacc26fc41745591175ef009e5e
