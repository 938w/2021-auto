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
// Inertial             inertial      9               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "function.h"
using namespace vex;
double lol = 1;
int main() {
// initialization
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // DRIVE FUNCTIONS : drivefunctions(direction, waittime) [fwd, rev, lft, rht]
  // STOP FUNCTIONS : stap(option); [drivetrain, frontlift, backlift, intake]
  // FRONT LIFT FUNCTIONS : FrontLift(dir, deg, wait?) [up, down]
  // BAK LIFT FUNCTIONS : BackLift(dir, deg, wait?) [up, down]
  SetVelocity(100);

// task 1 pick up the blue goal #1, NOT TUNED
  // deploy front lift
  FrontLift("down", 120, false);
  wait(1, sec);
  stap("frontlift");
  // mvoe forward to blue goal 1
  drivefunctions("fwd", 1);
  stap("drivetrain");
  // lift up blue goal on ramp
  FrontLift("up", 70, false);
  wait(0.8, sec);
  stap("frontlift");
// task 2 turn left and push neutral goal #1 to other side, NOT TUNED
  // drive back out of the platform
  drivefunctions("rev", 0.45);
  stap("drivetrain");
  wait(0.5, sec);
  //turn so doesnt hit wall
  SetVelocity(70); 
  FrontRight.spin(reverse);
  BackRight.spin(reverse);
  wait (0.2, sec);
  drivefunctions("fwd", 0.2);
  stap("drivetrain");
  FrontRight.spin(reverse);
  BackRight.spin(reverse);
  wait(0.58, sec);
  stap("drivetrain");
  wait (0.1, sec);
  drivesetstop();
  SetVelocity(100);
  wait(0.5, sec);
  //drive and push neutral goal
  drivefunctions("fwd", 5);
  stap("drivetrain");
  drivesetstop();
// task 3 turn right and put down blue goal #1, NOT TUNED
  drivefunctions("rev", 0.5);
  //
  drivefunctions("rht", 0.4);
  stap("drivetrain");
  drivesetstop();
  drivefunctions("fwd", 0.3);
  stap("drivetrain");
  //
  FrontLift("down", 70, false);
  wait(1, sec); 
  stap("frontlift");
  
// task 4 go forward and pick up red goal #2 and store, NOT TUNED
  //
  BackLift("down", 95, false);
  wait(1, sec);
  stap("backlift");
  //
  drivefunctions("rev", 0.6);
  stap("drivetrain");
  // lift up goal
  BackLift("up", 95, false);
  wait(1, sec);
  stap("backlift");
// task 5 around the neutral goal and pick up blue goal #2, NOT TUNED
  // back up a little
  drivefunctions("rev", 0.2);
  stap("drivetrain");
  // turn right 
  drivefunctions("rht", 0.9);
  stap("drivetrain");
  // forward
  drivefunctions("fwd", 3);
  stap("drivetrain");
  // 
// task 6 pick up neutral goal #3, NOT TUNED
// task 7 put down blue goal #2, NOT TUNED

// task 8 pick up red goal #1, NOT TUNED

// task 9 drive to the ramp, NOT TUNED


// task 10 go up the ramp, NOT TUNED
  Inertial.resetRotation();
  drivesetstop();
  FrontLift("down", 120, false);
  wait(1, sec);
  stap("frontlift");
  Inertial.resetRotation();
  wait(0.5, sec);
  FrontRight.spin(reverse);
  FrontLeft.spin(reverse);
  BackLeft.spin(reverse);
  BackRight.spin(reverse);
  wait(1, sec);
  FrontLift("up", 100, false);
  wait(0.2, sec);
  stap("drivetrain");
  SetVelocity(30);
  while (true) {
    Brain.Screen.clearScreen();
    Brain.Screen.newLine();
    Brain.Screen.print(Inertial.roll());
    wait(10, msec);
    lol = Inertial.roll();
    if (lol < 0) {
      lol = lol*-1;
    }
    SetVelocity((lol));
    if (Inertial.roll() < -10) {
      FrontRight.spin(reverse);
      FrontLeft.spin(reverse);
      BackLeft.spin(reverse);
      BackRight.spin(reverse);
    } else if (Inertial.roll() > 10) {
      FrontLeft.spin(forward);
      FrontRight.spin(forward);
      BackRight.spin(forward);
      BackLeft.spin(forward);
      
    } else {
      stap("drivetrain");
      drivesetstop();
    }
  }
}

