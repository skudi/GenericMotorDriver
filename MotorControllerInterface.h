#pragma once
#include "Arduino.h"

#ifndef PWMRANGE
#define PWMRANGE 255
#endif

class MotorControllerInterface{
  public:
    /**
     * \param power Number between -1 and 1 representing power to send to the motor (negative values cause motor to reverse)
     */
    virtual void set(double power) {
#ifdef DEBUGMOTOR
			Serial.print("(");
			Serial.print((unsigned long)this, 16);
			Serial.print(")MotorControllerInterface.set power:");
			Serial.print(power);
			Serial.print("\n");
#endif
		};

};


