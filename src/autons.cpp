#include "vex.h"

/**
 * Resets the constants for auton movement.
 * Modify these to change the default behavior of functions like
 * drive_distance(). For explanations of the difference between
 * drive, heading, turning, and swinging, as well as the PID and
 * exit conditions, check the docs.
 */

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(12, 1, .01, 2, 0);
  chassis.set_heading_constants(6, .5, 1, 1, 1);
  chassis.set_turn_constants(12, .5, .03, 4, 0);
  chassis.set_swing_constants(12, .3, .001, 2, 0);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  // Time is in miliseconds
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

/**
 * A little of this, a little of that; it should end roughly where it started.
 */
void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

void calibrate(){
  Brain.Screen.clearScreen();
  Gyro.calibrate();
  Brain.Screen.print("Inertial Calibrating");
}

void calibrateWithDelay(){
  Brain.Screen.clearScreen();
  Gyro.calibrate();
  Brain.Screen.print("Inertial Calibrating");
  Controller1.Screen.print("Inertial Calibrating");
  wait(5000,msec);
  Brain.Screen.print("Intertial Calibrated");
  Controller1.Screen.print("Inertial Calibrated");
}

void calibrateUntilAButton(){
  calibrate();
  int count = 0;
  Controller1.Screen.print("WAIT!!! GYRO IS CALIBRATING");
  while(!(Controller1.ButtonL1.pressing())){
    wait(50,msec);
    count += 50;
    if(count > 5000){}
  }
  Controller1.Screen.clearScreen();
  Controller1.Screen.print("Gyro Calibrated. Now Press A");
}

void turnTest(){

  calibrateWithDelay();

  float angle = 180;
  float turn_max_voltage = 10;
  float turn_settle_error = 3000;
  float turn_settle_time = 3000;
  float turn_timeout = 3000;

  chassis.turn_to_angle(angle, turn_max_voltage);
  while(1){
    Brain.Screen.print(Gyro.angle());
    Brain.Screen.newLine();
    Brain.Screen.print(Gyro.installed());
    Brain.Screen.newLine();
    Brain.Screen.print(Gyro.heading());
    wait(50,msec); //do not overwhelm the bot
    Brain.Screen.clearScreen();
  }
}

void timed_rush()
{
  //(float distance, float heading, float drive_max_voltage, float heading_max_voltage, float drive_settle_error, float drive_settle_time, float drive_timeout);
  chassis.drive_distance(-25);
  chassis.simpleTurnLeftforTime(600, 10);
}

/**
 * Sets constants to be more effective for odom movements.
 * For functions like drive_to_point(), it's often better to have
 * a slower max_voltage and greater settle_error than you would otherwise.
 */

void odom_constants(){
  default_constants();
  chassis.heading_max_voltage = 10;
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
  chassis.boomerang_lead = .5;
  chassis.drive_min_voltage = 0;
}

void gold_rush(){

  chassis.drive_distance(10);
}

void intakeOn(){
  IN.spin(forward, 127, pct);
  HK.spin(forward, 127, pct);
}

void intakeOff(){
  IN.stop(hold);
  HK.stop(hold);
}

void clampDown(){
  CL.set(true);
  lastClamp = true;
  wait(80,msec);
}

void clampUp(){
  CL.set(false);
  lastClamp = false;
  wait(80,msec)
}

void right_rush(){
  intakeOn();
  chassis.drive_distance(-50);
  chassis.turn_to_angle(30);
  chassis.drive_distance(-21);
  chassis.drive_distance(-4,0,6,0);
  clampDown();
  /*
  chassis.turn_to_angle(-15);
  chassis.drive_distance(6);
  chassis.turn_to_angle(70);
  chassis.drive_distance(15);
  chassis.turn_to_angle(0);
  chassis.drive_distance(15);
  */
}

void left_rush(){

}