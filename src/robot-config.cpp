#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;


brain  Brain;

motor LF = motor(PORT20,ratio6_1,true);
motor LM = motor(PORT19,ratio6_1,true);
motor LB = motor(PORT18,ratio6_1,true);

motor RF = motor(PORT11,ratio6_1,false);
motor RM = motor(PORT13,ratio6_1,false);
motor RB = motor(PORT12,ratio6_1,false);

motor IN = motor(PORT16,ratio18_1,false);
motor HK = motor(PORT10,ratio6_1,true);

motor LB = motor(PORT17,ratio18_1,true);

digital_out CL = digital_out(Brain.ThreeWirePort.A);

controller Controller1 = controller();
rotation Rotation = rotation(PORT2);

inertial Gyro = inertial(PORT1);

void vexcodeInit( void ) {

  calibrate();
  
}