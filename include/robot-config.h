using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FrontLeft;
extern motor FrontRight;
extern motor BackLeft;
extern motor BackRight;
extern motor MobileLift;
extern motor Intake;
extern motor MobileLift2;
extern motor LiftbACK;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );