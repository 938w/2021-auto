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
// BackLift             motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
void SetVelocity(int x) {
  MobileLift.setVelocity(100,percent);
  MobileLift.setMaxTorque(100,percent);
  MobileLift2.setVelocity(100,percent);
  MobileLift2.setMaxTorque(100,percent);
  BackLift.setVelocity(100,percent);
  BackLift.setMaxTorque(100,percent);
  FrontLeft.setVelocity(x,percent);
  FrontRight.setVelocity(x,percent);
  BackLeft.setVelocity(x,percent);
  BackRight.setVelocity(x,percent);
  Intake.setVelocity(100,percent);
  MobileLift.setPosition(0, degrees);
  MobileLift2.setPosition(0,degrees);
  MobileLift.setPosition(0, turns);
  MobileLift2.setPosition(0,turns);
}
void drivefunctions(std::string dir, double x) {
  SetVelocity(50);
  if (dir == "rev") {
    FrontLeft.spin(forward);
    FrontRight.spin(forward);
    BackRight.spin(forward);
    BackLeft.spin(forward);
    wait (x, sec);
  }
  if (dir == "fwd") {
    FrontRight.spin(reverse);
    FrontLeft.spin(reverse);
    BackLeft.spin(reverse);
    BackRight.spin(reverse);
    wait (x, sec);

  }
  if (dir == "lft") {
    FrontRight.setVelocity(30, percent);
    FrontLeft.setVelocity(30, percent);
    BackLeft.setVelocity(30, percent);
    BackRight.setVelocity(30, percent);
    FrontRight.spin(reverse);
    FrontLeft.spin(forward);
    BackRight.spin(reverse);
    BackLeft.spin(forward);
    wait (x, sec);
    FrontRight.setVelocity(100, percent);
    FrontLeft.setVelocity(100, percent);
    BackLeft.setVelocity(100, percent);
    BackRight.setVelocity(100, percent);
  }
  if (dir == "rht") {
    FrontRight.setVelocity(30, percent);
    FrontLeft.setVelocity(30, percent);
    BackLeft.setVelocity(30, percent);
    BackRight.setVelocity(30, percent);
    FrontRight.spin(forward);
    FrontLeft.spin(reverse);
    BackRight.spin(forward);
    BackLeft.spin(reverse);
    wait (x, sec);
    FrontRight.setVelocity(100, percent);
    FrontLeft.setVelocity(100, percent);
    BackLeft.setVelocity(100, percent);
    BackRight.setVelocity(100, percent);
  }
  SetVelocity(100);
}
void stap (std::string option) {
  if (option == "drivetrain") {
  FrontLeft.stop();
  FrontRight.stop();
  BackRight.stop();
  BackLeft.stop();
  }
  if (option == "frontlift") {
    MobileLift.stop();
    MobileLift2.stop();
  }
  if (option == "backlift") {
    BackLift.stop();
    BackLift.setStopping(hold);
  }
  if (option == "intake") {
    Intake.stop();
  }
}

void FrontLift (std::string dir, double x, bool wait) {
  if (dir == "up") {
    MobileLift.spinFor(forward, x*5, degrees, wait);
    MobileLift2.spinFor(forward, x*5, degrees, wait);
  }
  if (dir == "down") {
    MobileLift.spinFor(reverse, x*5, degrees, wait);
    MobileLift2.spinFor(reverse, x*5, degrees, wait);
  }
}
void BakLift (std::string dir, double x, bool wait) {
  if (dir == "up") {
    BackLift.spinFor(reverse, x*7, degrees, wait);
    
  }
  if (dir == "down") {
    BackLift.spinFor(forward, x*7, degrees, wait);
    
  }
}
void drivesetstop() {
  BackRight.setStopping(hold);
  BackLeft.setStopping(hold);
  FrontRight.setStopping(hold);
  FrontLeft.setStopping(hold);
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // PLAN:
  // start on the  left side
  // start backwards
  // drive to goal and pick up with backlift
  // DRIVE FUNCTIONS : drivefunctions(direction, waittime) [fwd, rev, lft, rht]
  // STOP FUNCTIONS : stap(option); [drivetrain, frontlift, backlift, intake]
  // FRONT LIFT FUNCTIONS : FrontLift(dir, deg, wait?) [up, down]
  // BAK LIFT FUNCTIONS : BakLift(dir, deg, wait?) [up, down]
  
  // PLAN:
  // start on the  left side
  SetVelocity(100);
  // start backwards
  // drive to goal and release lifts.
  BakLift("down", 100, false);
  wait(0.6, sec);
  SetVelocity(50);
  drivefunctions("rev", 0.5);
  SetVelocity(100);
  drivefunctions("rev", 0.75);
  stap("drivetrain");
  drivefunctions("rev", 2.4);
  stap("drivetrain");
  // pick up with backlift
  BakLift("up", 40, true);
  // turn 190 degrees right
  drivefunctions("rht", 2);
  stap("drivetrain");
  drivesetstop();
  FrontLift("down", 100, false);
  wait(1, sec);
  // go forward to corner
  drivefunctions("rev", 1);
  // turn to blue goal
  drivefunctions("lft", 0.97);
  // go forward to blue goal
  drivefunctions("fwd", 1.4);
  stap("drivetrain");
  // lift up blue
  FrontLift("up", 70, false);
  wait(1, sec);
  // back drive
  drivefunctions("rev", 1.4);
  drivefunctions("rht", 0.97);
  // back drive to home zone and turn a little
  drivefunctions("rev", 1.5);
  drivefunctions("rght", 0.2);
  drivefunctions("rev", 2.5);
  stap("drivetrain");
}
