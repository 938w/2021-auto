/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\Runchen                                          */
/*    Created:      Fri Dec 03 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         3               
// BackRight            motor         4               
// MobileLift           motor         5               
// Intake               motor         6               
// MobileLift2          motor         7               
// LiftbACK             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "function.h"
using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // DRIVE FUNCTIONS : drivefunctions(direction, waittime) [fwd, rev, lft, rht]
  // STOP FUNCTIONS : stap(option); [drivetrain, frontlift, backlift, intake]
  // FRONT LIFT FUNCTIONS : FrontLift(dir, deg, wait?) [up, down]
  // BAK LIFT FUNCTIONS : BackLift(dir, deg, wait?) [up, down]
  SetVelocity(100);

//task1 pick up blue goal 1
  // deploy front lift
  FrontLift("down", 120, false);
  wait(1, sec);
  stap("frontlift");
  // mvoe forward to blue goal 1
  drivefunctions("fwd", 1);
  stap("drivetrain");
  // lift up blue goal on ramp
  FrontLift("up", 50, false);
  wait(1, sec);
  stap("frontlift");

  
wait (1, sec);
//setup robot for neutral goal
  // drive back out of the platform
  drivefunctions("rev", 0.4);
  stap("drivetrain");
  wait(0.5, sec);
  //turn so doesnt hit wall
  FrontRight.setVelocity(80, percent);
  FrontLeft.setVelocity(830, percent);
  BackLeft.setVelocity(80, percent);
  BackRight.setVelocity(80, percent);
  FrontRight.spin(reverse);
  BackRight.spin(reverse);
  wait (0.8, sec);
  FrontRight.setVelocity(100, percent);
  FrontLeft.setVelocity(100, percent);
  BackLeft.setVelocity(100, percent);
  BackRight.setVelocity(100, percent);
  stap("drivetrain");
  drivesetstop();

  

wait(1, sec);
//drive and oush neutral goal
  drivefunctions("fwd", 3);
  stap("drivetrain");
  drivesetstop();





}

