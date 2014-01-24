
#include "TripleMotor.h"

TripleMotor::TripleMotor(SpeedController* speedController1,
			SpeedController* speedController2,
                        SpeedController* speedController3)
:mSpeedController1(speedController1),
 mSpeedController2(speedController2),
 mSpeedController3(speedController3)
{}

SpeedController* TripleMotor::GetSpeedController1()
{return mSpeedController1;}

SpeedController* TripleMotor::GetSpeedController2()
{return mSpeedController2;}

SpeedController* TripleMotor::GetSpeedController3()
{return mSpeedController3;}

void TripleMotor::Set(float speed, UINT8 syncGroup = 0)
{
	mSpeedController1->Set(speed, syncGroup);
	mSpeedController2->Set(speed, syncGroup);
        mSpeedController3->Set(speed, syncGroup);
}

float TripleMotor::Get()
{
	return mSpeedController1->Get();
}
void TripleMotor::Disable()
{
	mSpeedController1->Disable();
	mSpeedController2->Disable();
        mSpeedController3->Disable();
}

void TripleMotor::PIDWrite(float output)
{
	 Set(output);
}


