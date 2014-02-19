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
Encoder* RobotMap::chassisLeftEncoder = NULL;
Encoder* RobotMap::chassisRightEncoder = NULL;
Compressor* RobotMap::compressorSystemCompressor = NULL;
CANJaguar* RobotMap::intakeRoller = NULL;
DoubleSolenoid* RobotMap::intakeSolenoid = NULL;
Relay* RobotMap::intakeLights = NULL;
DoubleSolenoid* RobotMap::shifterShifter = NULL;
DoubleSolenoid* RobotMap::armPivotSolenoid = NULL;
DoubleSolenoid* RobotMap::shootershooterClutch = NULL;
CANJaguar* RobotMap::shootershooterWinch2 = NULL;
Ultrasonic* RobotMap::shooterUltrasonic = NULL;
CANJaguar* RobotMap::shootershooterWinch1 = NULL;
PIDController* RobotMap::shooterPIDController1 = NULL;
DigitalInput* RobotMap::shooterMagnetSwitch = NULL;
Relay* RobotMap::underglowLights = NULL;
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
DoubleMotor* RobotMap::shootershooterWinch = NULL;
void RobotMap::init() {
	chassisRightJaguar1 = new CANJaguar(2);
	chassisRightJaguar1->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	chassisRightJaguar2 = new CANJaguar(3);
	chassisRightJaguar2->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	chassisRightJaguar3 = new CANJaguar(4);
	chassisRightJaguar3->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	chassisLeftJaguar1 = new CANJaguar(5);
	chassisLeftJaguar1->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	chassisLeftJaguar2 = new CANJaguar(6);
	chassisLeftJaguar2->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	chassisLeftJaguar3 = new CANJaguar(7);
	chassisLeftJaguar3->ConfigNeutralMode(CANJaguar::kNeutralMode_Brake);
	chassisRightDrive = new TripleMotor(chassisRightJaguar1,
							chassisRightJaguar2,chassisRightJaguar3);
	
	chassisLeftDrive = new TripleMotor(chassisLeftJaguar1,
							chassisLeftJaguar2,chassisLeftJaguar3);
	chassisRobotDrive = new RobotDrive(chassisLeftDrive, chassisRightDrive);
	
	chassisRobotDrive->SetSafetyEnabled(true);
        chassisRobotDrive->SetExpiration(0.1);
        chassisRobotDrive->SetSensitivity(0.5);
        chassisRobotDrive->SetMaxOutput(1.0);
        
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	chassisLeftEncoder = new Encoder(1, 4, 1, 5, false, Encoder::k4X);
	lw->AddSensor("Chassis", "LeftEncoder", chassisLeftEncoder);
	chassisLeftEncoder->SetDistancePerPulse(0.05);
        chassisLeftEncoder->SetPIDSourceParameter(Encoder::kDistance);
        chassisLeftEncoder->Start();
	chassisRightEncoder = new Encoder(1, 6, 1, 7, false, Encoder::k4X);
	lw->AddSensor("Chassis", "RightEncoder", chassisRightEncoder);
	chassisRightEncoder->SetDistancePerPulse(0.05);
        chassisRightEncoder->SetPIDSourceParameter(Encoder::kDistance);
        chassisRightEncoder->Start();
	compressorSystemCompressor = new Compressor(1, 3, 1, 1);
	
	
	intakeRoller = new CANJaguar(8);
	
	
	intakeSolenoid = new DoubleSolenoid(1, 1, 5);      
	
	
	intakeLights = new Relay(1, 3);
	
	shifterShifter = new DoubleSolenoid(1, 2, 6);      
	
	
	armPivotSolenoid = new DoubleSolenoid(1, 3, 7);      
	
	
	shootershooterClutch = new DoubleSolenoid(1, 4, 8);      
	
	
	shootershooterWinch2 = new CANJaguar(10);
	
	
	shooterUltrasonic = new Ultrasonic(1, 1, 1, 2);
	lw->AddSensor("Shooter", "Ultrasonic", shooterUltrasonic);
	
	shootershooterWinch1 = new CANJaguar(9);
	
	
	/*shooterPIDController1 = new PIDController(1.0, 0.0, 0.0, F: 0.0,  shooterUltrasonic, shootershooterWinch1, 0.02);
	shooterPIDController1->SetContinuous(false); shooterPIDController1->SetAbsoluteTolerance(0.2); 
        shooterPIDController1->SetOutputRange(-1.0, 0.0);*/
	//shooterMagnetSwitch = new DigitalInput(1, 8);
	
	underglowLights = new Relay(1, 4);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	
	shootershooterWinch = new DoubleMotor(shootershooterWinch1, shootershooterWinch2);
	shooterPIDController1 = new PIDController(0.5, 0.0, 0.0,/* F: 0.0, */ shooterUltrasonic, shootershooterWinch, 0.02);
		shooterPIDController1->SetContinuous(false); shooterPIDController1->SetAbsoluteTolerance(0.2); 
	        shooterPIDController1->SetOutputRange(-1.0, 0.0);
	
}
