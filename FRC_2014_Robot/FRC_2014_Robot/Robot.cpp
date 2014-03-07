// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "SmartDashboard/SmartDashboard.h"
#include "WPILib.h"
#include "Commands/Shift.h"
#include "Commands/IntakeSwitchRoller.h"

/*double GetDistance()
{
	double distance = SmartDashboard::GetNumber("Distance");
	return distance;
}

void PrintDistance()
{
	double distance = SmartDashboard::GetNumber("Distance");
	char buf[10];
	sprintf(buf, "%7.3f", distance);
	DriverStationLCD::GetInstance()->Printf(DriverStationLCD::kUser_Line1, 1, buf);
	DriverStationLCD::GetInstance()->UpdateLCD();	
}*/

#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Chassis* Robot::chassis = 0;
CompressorSystem* Robot::compressorSystem = 0;
Intake* Robot::intake = 0;
Shifter* Robot::shifter = 0;
Arm* Robot::arm = 0;
Shooter* Robot::shooter = 0;
Underglow* Robot::underglow = 0;
OI* Robot::oi = 0;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

Preferences* Robot::robotPref = 0;

void Robot::RobotInit() {
	RobotMap::init();
	
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	chassis = new Chassis();
	compressorSystem = new CompressorSystem();
	intake = new Intake();
	shifter = new Shifter();
	arm = new Arm();
	shooter = new Shooter();
	underglow = new Underglow();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	
	oi = new OI();
	lw = LiveWindow::GetInstance();
	robotPref = Preferences::GetInstance();
	
	
	Robot::intake->solenoid->Set(DoubleSolenoid::kForward);
	Robot::shifter->shifter->Set(DoubleSolenoid::kReverse);
	Robot::arm->pivotSolenoid->Set(DoubleSolenoid::kForward);
	Robot::shooter->shooterClutch->Set(DoubleSolenoid::kForward);
	Robot::chassis->robotDrive
					->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	Robot::chassis->robotDrive
					->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
	
	autoChooser = new SendableChooser();
	autoChooser->AddDefault("Shift", new Shift());
	autoChooser->AddObject("Intake", new IntakeSwitchRoller());
	SmartDashboard::PutData("AutoChooser", autoChooser);
  }
	
void Robot::AutonomousInit() {
	// instantiate the command used for the autonomous period
	autonomousCommand = (Command*)(autoChooser->GetSelected());

	if (autonomousCommand != NULL)
		autonomousCommand->Start();
	
}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	Robot::shooter->shooterClutch->Set(DoubleSolenoid::kForward);
	autonomousCommand->Cancel();
}
	
void Robot::TeleopPeriodic() {
	SmartDashboard::PutNumber("rangeSample", Robot::shooter->rangeSample);
	SmartDashboard::PutNumber("GoalDistance", Robot::robotPref->GetDouble("GoalDistance", 0.0));
	SmartDashboard::PutNumber("LeftEncoder", 
							Robot::chassis->leftEncoder->GetDistance());
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();

}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
