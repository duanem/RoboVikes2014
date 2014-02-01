// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
Compressor* RobotMap::compressorSystemCompressor = NULL;
CANJaguar* RobotMap::intakeRoller = NULL;
DoubleSolenoid* RobotMap::intakeSolenoid = NULL;
DoubleSolenoid* RobotMap::shifterShifter = NULL;
CANJaguar* RobotMap::shootershooterWinch = NULL;
DoubleSolenoid* RobotMap::shootershooterClutch = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
CANJaguar* RobotMap::chassisLeftJaguar1 = NULL;
CANJaguar* RobotMap::chassisRightJaguar1 = NULL;
CANJaguar* RobotMap::chassisLeftJaguar2 = NULL;
CANJaguar* RobotMap::chassisRightJaguar2 = NULL;
CANJaguar* RobotMap::chassisLeftJaguar3 = NULL;
CANJaguar* RobotMap::chassisRightJaguar3 = NULL;
TripleMotor* RobotMap::chassisLeftDrive = NULL;
TripleMotor* RobotMap::chassisRightDrive = NULL;
RobotDrive* RobotMap::chassisRobotDrive = NULL;
void RobotMap::init() {
	chassisLeftJaguar1 = new CANJaguar(2);
	chassisLeftJaguar2 = new CANJaguar(3);
	chassisLeftJaguar3 = new CANJaguar(4);
	
	chassisRightJaguar1 = new CANJaguar(5);
	chassisRightJaguar2 = new CANJaguar(6);
	chassisRightJaguar3 = new CANJaguar(7);
	
	chassisLeftDrive = new TripleMotor(chassisLeftJaguar1,
							chassisLeftJaguar2,chassisLeftJaguar3);
	chassisRightDrive = new TripleMotor(chassisRightJaguar1,
							chassisRightJaguar2,chassisRightJaguar3);
	chassisRobotDrive = new RobotDrive(chassisLeftDrive, chassisRightDrive);
	
	chassisRobotDrive->SetSafetyEnabled(true);
        chassisRobotDrive->SetExpiration(0.1);
        chassisRobotDrive->SetSensitivity(0.5);
        chassisRobotDrive->SetMaxOutput(1.0);
        
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	compressorSystemCompressor = new Compressor(1, 1, 1, 1);
	
	
	intakeRoller = new CANJaguar(8);
	
	
	intakeSolenoid = new DoubleSolenoid(1, 1, 5);      
	
	
	shifterShifter = new DoubleSolenoid(1, 2, 6);      

	shootershooterWinch = new CANJaguar(9);
	
	
	shootershooterClutch = new DoubleSolenoid(1, 4, 8);
	
	
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
