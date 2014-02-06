/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2011. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#ifndef THROTTLEBUTTON_H__
#define THROTTLEBUTTON_H__

#include "Buttons/JoystickButton.h"

class ThrottleButton : public Button
{
public:
	typedef enum
	{
		kPositive = false,
		kNegative = true
	}Direction;
	
	ThrottleButton(GenericHID *joystick, int axisNumber, 
			    double threshold, Direction direction=kPositive);
	virtual ~ThrottleButton() {}

	virtual bool Get();

private:
	GenericHID *m_joystick;
	int m_axisNumber;
	bool m_negativeDirection;
	double m_threshold;
};

#endif
