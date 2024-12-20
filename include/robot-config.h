using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;

extern motor LF;
extern motor LM;
extern motor LB;

extern motor RF;
extern motor RM;
extern motor RB;

extern motor IN;
extern motor LT;
extern motor HK;

extern digital_out CL;

//Add your devices below, and don't forget to do the same in robot-config.cpp:

extern controller Controller1;

extern inertial Gyro;

extern optical Optical;
extern distance Distance;

void vexcodeInit( void );