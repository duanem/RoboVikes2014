// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Chassis* Robot::chassis = 0;
CompressorSystem* Robot::compressorSystem = 0;
Intake* Robot::intake = 0;
Shifter* Robot::shifter = 0;
Arm* Robot::arm = 0;
Shooter* Robot::shooter = 0;
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
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	robotPref = Preferences::GetInstance();
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	Robot::intake->solenoid->Set(DoubleSolenoid::kForward);
	Robot::shifter->shifter->Set(DoubleSolenoid::kForward);
	Robot::arm->pivotSolenoid->Set(DoubleSolenoid::kForward);
	Robot::shooter->shooterClutch->Set(DoubleSolenoid::kForward);
  }
	
void Robot::AutonomousInit() {
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
	
	autonomousCommand->Cancel();
}
	
void Robot::TeleopPeriodic() {
	SmartDashboard::PutNumber("rangeSample", Robot::shooter->rangeSample);
	SmartDashboard::PutNumber("IntakeValue", Robot::robotPref->GetDouble("IntakeValue", 0.0));
	SmartDashboard::PutNumber("GoalDistance", Robot::robotPref->GetDouble("GoalDistance", 0.0));
	SmartDashboard::PutNumber("DriveSpeed", Robot::robotPref->GetDouble("DriveSpeed", 0.0));
	SmartDashboard::PutNumber("DriveAngle", Robot::robotPref->GetDouble("DriveAngle", 0.0));
	SmartDashboard::PutNumber("ShooterSetpoint", Robot::robotPref->GetDouble("ShooterSetpoint", 0.0));
	SmartDashboard::PutNumber("ShooterP", Robot::robotPref->GetDouble("ShooterP", 0.0));
	SmartDashboard::PutNumber("IntakePos",Robot::intake->solenoid->Get());
	SmartDashboard::PutNumber("ShooterPos",Robot::arm->pivotSolenoid->Get());
	SmartDashboard::PutNumber("ClutchPos", Robot::shooter->shooterClutch->Get());
	SmartDashboard::PutNumber("ShiftPos",Robot::shifter->shifter->Get());

	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
