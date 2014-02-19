// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "TripleMotor.h"
#include "DoubleMotor.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Encoder* chassisLeftEncoder;
	static Encoder* chassisRightEncoder;
	static Compressor* compressorSystemCompressor;
	static CANJaguar* intakeRoller;
	static DoubleSolenoid* intakeSolenoid;
	static Relay* intakeLights;
	static DoubleSolenoid* shifterShifter;
	static DoubleSolenoid* armPivotSolenoid;
	static DoubleSolenoid* shootershooterClutch;
	static CANJaguar* shootershooterWinch2;
	static Ultrasonic* shooterUltrasonic;
	static CANJaguar* shootershooterWinch1;
	static PIDController* shooterPIDController1;
	static Relay* underglowLights;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANJaguar* chassisLeftJaguar1;
	static CANJaguar* chassisLeftJaguar2;
	static CANJaguar* chassisLeftJaguar3;
	static CANJaguar* chassisRightJaguar1;
	static CANJaguar* chassisRightJaguar2;
	static CANJaguar* chassisRightJaguar3;
	static TripleMotor* chassisLeftDrive;
	static TripleMotor* chassisRightDrive;
	static RobotDrive* chassisRobotDrive;
	
	static DoubleMotor* shootershooterWinch;
	static void init();
};
#endif
