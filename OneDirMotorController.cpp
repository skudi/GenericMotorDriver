#include "Arduino.h"
#include "OneDirMotorController.h"

OneDirMotorController::OneDirMotorController(unsigned int pin1) 
	: OneDirMotorController::OneDirMotorController(pin1, 1.0)
{}

OneDirMotorController::OneDirMotorController(unsigned int pin1, float cutOff) {
	Serial.print("OneDirMotorController.new pin:");
	Serial.print(pin1);
	Serial.print("\n");
	this->cutOff = cutOff;
	this->pin = pin1;
	pinMode(this->pin, OUTPUT);
}

void OneDirMotorController::set(double power){
  if (power > 1) power = 1;
  else if (power < -1) power = -1;
	power = (power + 1.0) / 2.0;
	if (power > this->cutOff) {
		power = this->cutOff;
	}
	MotorControllerInterface::set(power);
	analogWrite(this->pin, PWMRANGE*power);
}


