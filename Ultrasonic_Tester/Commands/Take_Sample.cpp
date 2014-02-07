// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.


#include "Take_Sample.h"

Take_Sample::Take_Sample() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::sample);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void Take_Sample::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void Take_Sample::Execute() {
	Robot::sample->ultrasonic->SetAutomaticMode(true);
	// Robot::sample->ultrasonic->Ping();
	
	Robot::sample->range_sample = (Robot::sample->ultrasonic->GetRangeInches());
	double distance = Robot::sample->range_sample;
	
	if (distance < 50 && distance > 0) {
		DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line1, 1, "0 < x < 50     ");
	} else if (distance < 100 && distance >= 50) {
		DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line1, 1, "50 <= x < 100     ");
	} else {
		DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line1, 1, "100 <= x     ");
	}
	
	/*
	if (Robot::sample->ultrasonic->GetRangeInches() != 0.0) {
		DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line1, 1, "not 0");
	} else {
		DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line1, 1, "is 0");
	}*/
	
	DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line2, 1, "1:56pm");
	
	DriverStationLCD::GetInstance()->UpdateLCD();
}

// Make this return true when this Command no longer needs to run execute()
bool Take_Sample::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Take_Sample::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Take_Sample::Interrupted() {

}
