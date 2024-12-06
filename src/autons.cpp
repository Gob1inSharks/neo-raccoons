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
  chassis.set_heading_constants(6, .5, 0.01, 2, 0);
  chassis.set_turn_constants(12, .5, .03, 4, 0);
  chassis.set_swing_constants(12, .3, .001, 2, 0);

  // Each exit condition set is in the form of (settle_error, settle_time, timeout).
  // Time is in miliseconds
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
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

void showGyroOnScreen(){
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print(Gyro.angle());
  Controller1.Screen.newLine();
  Controller1.Screen.print(Gyro.heading());
  Controller1.Screen.newLine();
  Controller1.Screen.print(Gyro.acceleration(yaxis));
}

void showGyroFinished(){
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print("GYRO CALIBRATED");
  Controller1.Screen.newLine();
  Controller1.Screen.print("You're Good to Go");
  Controller1.Screen.newLine();
  Controller1.Screen.print("Good Luck!");
}

/*
for gyro calibration
must call before auton
*/
void calibrate(){

  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);
  Controller1.Screen.print("GYRO CALIBRATING");

  Gyro.calibrate();

  int WAIT_TIME = 5000; //DO NOT CHANGE THIS VALUE
  wait(WAIT_TIME,msec);

  int DELAY_TIME = 200;
  int clock = 0;
  while(clock < WAIT_TIME){
    showGyroOnScreen();
    wait(DELAY_TIME,msec);
    clock += DELAY_TIME;
  }

  //showGyroFinished();
}

void calibrateWithDelay(){
  Brain.Screen.clearScreen();
  Gyro.calibrate();
  Brain.Screen.print("WAIT: Inertial Calibrating");
  Controller1.Screen.print("WAIT: Inertial Calibrating");
  wait(5000,msec);
  Controller1.Screen.clearLine();
  Brain.Screen.clearScreen();
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

void turn_test(){

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

void intakeOn(){
  IN.spin(reverse, 127, pct);
  HK.spin(reverse, 127, pct);
}

void intakeOff(){
  IN.stop(hold);
  HK.stop(hold);
}

void clampDown(){
  CL.set(false);
  //lastClamp = true;
  wait(200,msec);
}

void clampUp(){
  CL.set(true);
  //lastClamp = false;
  wait(200,msec);
}

void liftDown(){
  LT.spin(forward, 5, pct);
}

void liftHold(){
  LT.stop(hold);
}

void intakeForTime(int time){
  intakeOn();
  wait(time,msec);
  intakeOff();
}

void start(){
  liftDown();
  clampDown();
}

/*

This simply goes forward and takes the mogo as fast as possible
*/
void mogo_rush(){

  chassis.drive_distance(-14,0,12,4,
                            2,
                            50,
                            2000);
  chassis.drive_distance(-7,0,8,0,
                            2,
                            1,
                            5000);

  clampUp();
  //intakeOn();
  
  chassis.drive_distance(-3,0,8,0,
                            2,
                            1,
                            5000);
}

/*
This simply goes forward and takes the mogo as fast as possible,
then dumps the load ring if wanted
*/
void mogo_rush_with_ring(){

  chassis.drive_distance(-18,0,12,4,
                            2,
                            50,
                            2000);
  chassis.drive_distance(-3,0,8,0,
                            2,
                            1,
                            5000);
                            
  clampUp();
  intakeOn();
  
  chassis.drive_distance(-3,0,8,0,
                            2,
                            1,
                            5000);

  intakeOff();

}


void red_rings(){

  chassis.turn_to_angle(140,12,
                        3,
                        10,
                        5000);

  chassis.drive_distance(25,0,12,0,
                        1.5,
                        10,
                        5000);

  wait(200,msec);

  chassis.drive_distance(-5,0,12,0,
                         1.5,
                         300,
                         5000);

  chassis.turn_to_angle(115,12,
                        3,
                        10,
                        5000);

  chassis.drive_distance(9,0,12,0,
                         1,
                         10,
                         5000);

  chassis.drive_distance(-10,0,12,0,
                          1.5,
                          300,
                          5000);

  chassis.turn_to_angle(40,12,
                        3,
                        10,
                        5000);

  chassis.drive_distance(10,0,12,0,
                          1.5,
                          300,
                          5000);
}

void blue_rings(){

  chassis.turn_to_angle(140,12,
                        3,
                        10,
                        5000);

  chassis.drive_distance(25,0,12,0,
                        1.5,
                        10,
                        5000);

  wait(200,msec);

  chassis.drive_distance(-5,0,12,0,
                         1.5,
                         300,
                         5000);

  chassis.turn_to_angle(115,12,
                        3,
                        10,
                        5000);

  chassis.drive_distance(9,0,12,0,
                         1,
                         10,
                         5000);

  chassis.drive_distance(-10,0,12,0,
                          1.5,
                          300,
                          5000);

  chassis.turn_to_angle(40,12,
                        3,
                        10,
                        5000);

  chassis.drive_distance(10,0,12,0,
                          1.5,
                          300,
                          5000);
}

void blue_simple_AWP(){

  start();

  mogo_rush_with_ring();

  clampDown(); //let go of mogo one to get mogo two
  chassis.drive_distance(5,0,12,0,
                          2,10,500); //drive backwards a bit to turn better

  chassis.turn_to_angle(140,12,3,100,5000); //turn and get mogo 2
  chassis.drive_distance(-10,0,12,0,
                          1.5,
                          100,
                          5000);
  chassis.drive_distance(-3,0,8,0,
                          1.5,
                          300,
                          5000);
  clampUp();

  chassis.drive_distance(2,0,12,0,
                          2,10,500); //drive backwards a bit to turn better
  chassis.turn_to_angle(115,12,3,10,5000); //turn and get second ring
  intakeOn();
  chassis.drive_distance(10,0,12,0,
                          1.5,
                          10,
                          5000);

  //turn and RUN TOWARDS THE LADDER RUN!

  chassis.turn_to_angle(-40,12,3,10,5000);
  chassis.drive_distance(10,0,12,0); 
}

void red_simple_AWP(){

  start();

  mogo_rush_with_ring();

  clampDown(); //let go of mogo one to get mogo two
  chassis.drive_distance(2,0,12,0,
                          2,10,500); //drive backwards a bit to turn better

  chassis.turn_to_angle(-140,12,3,10,5000); //turn and get mogo 2
  chassis.drive_distance(-10,0,12,0,
                          1.5,
                          10,
                          5000);
  chassis.drive_distance(-3,0,8,0,
                          1.5,
                          300,
                          5000);
  clampUp();

  chassis.drive_distance(2,0,12,0,
                          2,10,500); //drive backwards a bit to turn better
  chassis.turn_to_angle(-115,12,3,10,5000); //turn and get second ring
  intakeOn();
  chassis.drive_distance(10,0,12,0,
                          1.5,
                          10,
                          5000);

  //turn and RUN TOWARDS THE LADDER RUN!

  chassis.turn_to_angle(-40,12,3,10,5000);
  chassis.drive_distance(10,0,12,0); 
}

/*
DO NOT CHANGE THESE FOUR FUNCTIONS BELOW
WE KNOW THAT THEY WORK, SO JUST IN CASE DO NOT TOUCH THEM AT ALL
*/

void red_mogo_rush(){
  liftDown();
  clampDown();
  chassis.drive_distance(-14,0,12,4,1,100,5000);
  chassis.drive_distance(-7,0,5,0);
  clampUp();
  intakeOn();
  intakeForTime(500);
  chassis.turn_to_angle(102,12,3,10,5000);
}

void red_four_rings_rush(){

  liftDown();
  clampDown();
  chassis.drive_distance(-14,0,12,4,1,100,5000);
  chassis.drive_distance(-7,0,8,0);
  clampUp();
  //chassis.drive_stop();
  intakeOn();
  wait(500,msec);
  chassis.turn_to_angle(140,12,3,10,5000);
  chassis.drive_distance(25,0,12,0,1.5,10,5000);
  wait(500,msec);
  chassis.drive_distance(-5,0,12,0);
  chassis.turn_to_angle(115,12,3,10,5000);
  chassis.drive_distance(8,0,12,0,1,10,5000);
  //clampDown();
  chassis.drive_distance(-9,0,12,0);

  chassis.turn_to_angle(40,12,3,10,5000);
  chassis.drive_distance(10,0,12,0);

  //clampDown();
}

void blue_four_rings_rush(){

  liftDown();
  wait(2000,msec);
  clampUp();

  chassis.drive_distance(-14,0,12,4,1,100,5000);
  chassis.drive_distance(-7,0,8,0);
  wait(200,msec);
  clampDown();
  //chassis.drive_stop();
  intakeOn();
  wait(500,msec);
  chassis.turn_to_angle(-140,12,3,300,5000);
  chassis.drive_distance(25,0,12,0,1.5,300,5000);
  wait(500,msec);
  chassis.drive_distance(-5,0,12,0);
  chassis.turn_to_angle(-115,12,3,300,5000);
  chassis.drive_distance(10,0,12,0,1,300,5000);
  //clampDown();
  chassis.drive_distance(-9,0,12,0);

  chassis.turn_to_angle(-40,12,3,300,5000);
  chassis.drive_distance(10,0,12,0);

  //clampDown();
}

void blue_mogo_rush(){
  liftDown();
  clampDown();
  chassis.drive_distance(-14,0,12,4,1,100,5000);
  chassis.drive_distance(-7,0,5,0);
  clampUp();
  intakeOn();
  intakeForTime(500);
  chassis.turn_to_angle(102,12,3,10,5000);
}

void red_six_rings(){

  red_four_rings_rush();

  chassis.turn_to_angle(30,12,
                        1,
                        500,
                        5000);

  chassis.drive_distance(10,0,12,0,
                         1.5,
                         300,
                         5000);
  chassis.drive_distance(4,0,8,0,
                         1.5,
                         300,
                         5000);

  chassis.turn_to_angle(60,12,
                        1,
                        500,
                        5000);
  chassis.turn_to_angle(30,12,
                        1,
                        500,
                        5000);

}

void experimentA(){

  calibrate();

  start();

  mogo_rush_with_ring();

}

void experimentB(){

  calibrate();

  start();

  mogo_rush_with_ring();

  chassis.turn_to_angle(-140,12,3,10,5000);
  chassis.drive_distance(25,0,12,0,1.5,10,5000);
  wait(500,msec);
  chassis.drive_distance(-5,0,12,0);
  chassis.turn_to_angle(-115,12,3,10,5000);
  chassis.drive_distance(9,0,12,0,1,10,5000);
  //clampDown();
  chassis.drive_distance(-10,0,12,0);

  chassis.turn_to_angle(-40,12,3,10,5000);
  chassis.drive_distance(10,0,12,0);

}

void experimentC(){

  calibrate();

  blue_simple_AWP();

}

void experimentD(){

  calibrate();

  red_simple_AWP();

}