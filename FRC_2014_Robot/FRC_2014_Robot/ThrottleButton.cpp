#include "ThrottleButton.h"
#include "Joystick.h"

ThrottleButton::ThrottleButton(GenericHID *joystick, int axisNumber, 
		                double threshold, Direction direction)
:m_joystick(joystick),
 m_axisNumber(axisNumber),
 m_negativeDirection(direction),
 m_threshold(threshold)
{
	
}

bool ThrottleButton::Get()
{
	if(m_negativeDirection)
		return m_joystick->GetRawAxis(m_axisNumber) < m_threshold;
	else
		return m_joystick->GetRawAxis(m_axisNumber) > m_threshold;
}
