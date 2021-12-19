#include "vex.h"

void SetVelocity(int x) {
  MobileLift.setVelocity(100,percent);
  MobileLift.setMaxTorque(100,percent);
  MobileLift2.setVelocity(100,percent);
  MobileLift2.setMaxTorque(100,percent);
  LiftbACK.setVelocity(100,percent);
  LiftbACK.setMaxTorque(100,percent);
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
    FrontRight.setVelocity(80, percent);
    FrontLeft.setVelocity(830, percent);
    BackLeft.setVelocity(80, percent);
    BackRight.setVelocity(80, percent);
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
    FrontRight.setVelocity(80, percent);
    FrontLeft.setVelocity(80, percent);
    BackLeft.setVelocity(80, percent);
    BackRight.setVelocity(80, percent);
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
    LiftbACK.stop();
    LiftbACK.setStopping(hold);
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
void BackLift (std::string dir, double x, bool wait) {
  if (dir == "up") {
    LiftbACK.spinFor(reverse, x*7, degrees, wait);
    
  }
  if (dir == "down") {
    LiftbACK.spinFor(forward, x*7, degrees, wait);
    
  }
}
void drivesetstop() {
  BackRight.setStopping(hold);
  BackLeft.setStopping(hold);
  FrontRight.setStopping(hold);
  FrontLeft.setStopping(hold);
}