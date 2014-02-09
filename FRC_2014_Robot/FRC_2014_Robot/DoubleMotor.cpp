
#include "DoubleMotor.h"

DoubleMotor::DoubleMotor(SpeedController* speedController1,
			SpeedController* speedController2)
:mSpeedController1(speedController1),
 mSpeedController2(speedController2)
{}

SpeedController* DoubleMotor::GetSpeedController1()
{return mSpeedController1;}

SpeedController* DoubleMotor::GetSpeedController2()
{return mSpeedController2;}

void DoubleMotor::Set(float speed, UINT8 syncGroup = 0)
{
	mSpeedController1->Set(speed, syncGroup);
	mSpeedController2->Set(speed, syncGroup);
}

float DoubleMotor::Get()
{
	return mSpeedController1->Get();
}
void DoubleMotor::Disable()
{
	mSpeedController1->Disable();
	mSpeedController2->Disable();
}

void DoubleMotor::PIDWrite(float output)
{
	 Set(output);
}


