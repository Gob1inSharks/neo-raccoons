#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;


double maxLiftAngle;
bool liftIsAtMaxHeight;
void liftRotateToMax(void);

double minLiftAngle;
bool liftIsAtMinHeight;
void liftRotateToMin(void);

bool clampDown;
bool liftUp;
void usercontrol(void);