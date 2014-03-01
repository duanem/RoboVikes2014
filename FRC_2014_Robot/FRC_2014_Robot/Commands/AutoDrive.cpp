// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "AutoDrive.h"
AutoDrive::AutoDrive()
:driveDistance(0.0),
 goalDistance(0.0)
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::chassis);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	Robot::chassis->leftEncoder->Reset();
	driveDistance = 0;
	Robot::chassis->robotDrive
					->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	Robot::chassis->robotDrive
					->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
}
// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=EXECUTE
	
	driveDistance = Robot::chassis->leftEncoder->GetDistance();
	SmartDashboard::PutNumber("LeftEncoder", driveDistance);
	goalDistance = Robot::robotPref->GetDouble("GoalDistance", 0);
	Robot::chassis->robotDrive->Drive(Robot::robotPref->GetDouble("DriveSpeed" , 0), 
				   Robot::robotPref->GetDouble("DriveAngle", 0));
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=EXECUTE
}
// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ISFINISHED
        // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ISFINISHED
	//return driveDistance < goalDistance;
	
	return driveDistance > goalDistance || driveDistance == goalDistance;
}
// Called once after isFinished returns true
void AutoDrive::End() {
	Robot::chassis->robotDrive->Drive(0.0, 0.0);
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {
	Robot::chassis->robotDrive->Drive(0.0, 0.0);
}
