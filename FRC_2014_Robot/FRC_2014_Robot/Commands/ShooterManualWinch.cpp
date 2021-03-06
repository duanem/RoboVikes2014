// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "ShooterManualWinch.h"
ShooterManualWinch::ShooterManualWinch() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void ShooterManualWinch::Initialize() {
	Robot::shooter->pIDController1->Disable();
	Robot::shooter->ultrasonic->SetAutomaticMode(true);
}
// Called repeatedly when this Command is scheduled to run
void ShooterManualWinch::Execute() {
	double sample = Robot::shooter->ultrasonic->GetRangeInches();
	if(sample < 50.0)
	{
		Robot::shooter->rangeSample = sample;	
	}
	double readValue = Robot::oi->getCoDriver()->GetRawAxis(2);
	if(readValue > 0.1)
	{		
		readValue *= -1;
		Robot::shooter->shooterWinch->Set(readValue);
	}
	else
	{
		Robot::shooter->shooterWinch->Set(0.0);
	}
}
// Make this return true when this Command no longer needs to run execute()
bool ShooterManualWinch::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void ShooterManualWinch::End() {
	Robot::shooter->shooterWinch->Set(0.0);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterManualWinch::Interrupted() {
	Robot::shooter->shooterWinch->Set(0.0);
}
