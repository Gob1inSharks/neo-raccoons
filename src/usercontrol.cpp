#include "vex.h"

bool clampDown = false;

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    chassis.control_arcade(); //look in JAR-Template/drive.h for more info

    //intake + hook HOLD DOWN
    if(Controller1.ButtonR1.pressing()) {
      IN.spin(forward, 127, pct);
      HK.spin(forward, 127, pct);
    } else if(Controller1.ButtonR2.pressing()) {
      IN.spin(reverse, 127, pct);
      HK.spin(reverse, 127, pct);
    } else {
      IN.stop(hold);
      HK.stop(hold);
    }

    //clamp TOGGLE
    if (Controller1.ButtonA.pressing()) {
      if (clampDown) {
        clampDown = false;
      } else {
        clampDown = true;
      }
    }
    if (clampDown) {
      CL.set(true);
      wait(80,msec);
    } else {
      CL.set(false);
      wait(80,msec);
    }

    //lift TODO after rotation is installed

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted memory
  }
}