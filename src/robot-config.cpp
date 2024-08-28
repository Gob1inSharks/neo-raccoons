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
bool LEFT_REVERSED = false;

motor LF = motor(,ratio6_1,false);
motor LM = motor(,ratio6_1,false);
motor LB = motor(,ratio6_1,false);

bool RIGHT_REVERSED = false;

motor RF = motor(,ratio6_1,false);
motor RM = motor(,ratio6_1,false);
motor RB = motor(,ratio6_1,false);

//Add your devices below, and don't forget to do the same in robot-config.h:

controller Controller;

void vexcodeInit( void ) {
  // nothing to initialize
}