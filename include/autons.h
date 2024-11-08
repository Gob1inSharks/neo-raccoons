#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

void drive_test();
void turn_test();
void turnTest();
void swing_test();
void full_test();
void odom_test();
void tank_odom_test();
void holonomic_odom_test();
void gold_rush();
void timed_rush();
void calibrate();
void calibrateWithDelay();

void calibrateUntilAButton();

void left_rush();
void right_rush();
void mogo_rush();
void ring_rush();
void red_mogo_rush();
void blue_mogo_rush();
void red_ring_rush();
void blue_ring_rush();