#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen.
brain  Brain;

//The motor constructor takes motors as (port, ratio, reversed), so for example
//motor LeftFront = motor(PORT1, ratio6_1, false);

// TODO, put PORTS!!!

//false is forward, true is reverse

//output devices

//reverse turning direction in JAR-Template/drive.cpp
motor LF = motor(PORT20,ratio6_1,true);
motor LM = motor(PORT19,ratio6_1,true);
motor LB = motor(PORT18,ratio6_1,true);

motor RF = motor(PORT11,ratio6_1,false);
motor RM = motor(PORT13,ratio6_1,false);
motor RB = motor(PORT12,ratio6_1,false);

motor IN = motor(PORT16,ratio18_1,false);
motor HK = motor(PORT10,ratio6_1,true);
motor LT = motor(PORT17,ratio18_1,true);

digital_out CL = digital_out(Brain.ThreeWirePort.A);

//input devices
controller Controller1 = controller();

optical Optical = optical(PORT3);
distance Distance = distance(PORT4);

inertial Gyro = inertial(PORT1);

void vexcodeInit( void ) {

  calibrate();
  // nothing to initialize
}