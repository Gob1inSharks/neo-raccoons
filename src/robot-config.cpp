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

//reverse turning direction in drive.cpp
motor LF = motor(PORT20,ratio6_1,false);
motor LM = motor(PORT19,ratio6_1,false);
motor LB = motor(PORT18,ratio6_1,false);

motor RF = motor(PORT11,ratio6_1,true);
motor RM = motor(PORT13,ratio6_1,true);
motor RB = motor(PORT12,ratio6_1,true);

motor IN = motor(PORT16,ratio18_1,false);
motor HK = motor(PORT10,ratio6_1,false);
motor LT = motor(PORT17,ratio18_1,false);

digital_out CL = digital_out(Brain.ThreeWirePort.A);

//input devices
controller Controller1 = controller();
rotation RotaryEncoder = rotation(,false);

void vexcodeInit( void ) {
  // nothing to initialize
}