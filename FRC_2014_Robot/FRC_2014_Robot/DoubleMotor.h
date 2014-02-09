#ifndef DOUBLE_MOTOR_H_
#define DOUBLE_MOTOR_H_

#include "SpeedController.h"
class DoubleMotor: public SpeedController
{
public:
	DoubleMotor(SpeedController* speedController1,
				SpeedController* speedController2);
	
	SpeedController* GetSpeedController1();	
	SpeedController* GetSpeedController2();	
	virtual void Set(float speed, UINT8 syncGroup);
	virtual float Get();
	
	virtual void Disable();
	
	virtual void PIDWrite(float output);
protected:
	SpeedController* mSpeedController1;
	SpeedController* mSpeedController2;
};

#endif
