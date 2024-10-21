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

motor LF = motor(,ratio6_1,false);
motor LM = motor(,ratio6_1,false);
motor LB = motor(,ratio6_1,false);

motor RF = motor(,ratio6_1,false);
motor RM = motor(,ratio6_1,false);
motor RB = motor(,ratio6_1,false);

motor IN = motor(,ratio18_1,false);
motor HK = motor(,ratio6_1,false);
motor LT = motor(,ratio18_1,false);

//Add your devices below, and don't forget to do the same in robot-config.h:

controller Controller = controller();
rotation RotaryEncoder = rotation(,false);

void vexcodeInit( void ) {
  // nothing to initialize
}