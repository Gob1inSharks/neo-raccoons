#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(12, 1, .01, 2, 0);
  chassis.set_heading_constants(6, .5, 0.01, 2, 0);
  chassis.set_turn_constants(12, .5, .03, 4, 0);
  chassis.set_swing_constants(12, .3, .001, 2, 0);

  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void calibrate(){

  Gyro.calibrate();
}

void calibrateWithDelay(){

  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1,1);

  Gyro.calibrate();

  int WAIT_TIME = 5000; //DO NOT CHANGE THIS VALUE
  wait(WAIT_TIME,msec);

  int foo = 0;
  while(foo < 5000){
    Controller1.Screen.print(Gyro.angle());
    Controller1.Screen.newLine();
    Controller1.Screen.print(Gyro.heading());
    Controller1.Screen.newLine();
    Controller1.Screen.print(Gyro.acceleration(yaxis)); 
    
    wait(10,msec);
    foo += 10;
  }
}