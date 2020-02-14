#include "MotorControllerInterface.h"

class OneDirMotorController : public MotorControllerInterface {
	protected:
		float cutOff = 1.0;
		uint8_t pin = -1;
  public:
    OneDirMotorController(unsigned int pin1);
    OneDirMotorController(unsigned int pin1, float cutoff);

    virtual void set(double power);
};

