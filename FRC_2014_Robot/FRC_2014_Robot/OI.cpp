// RobotBuilder Version: 1.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/ArmPivotSwitch.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/ChassisReverseDrive.h"
#include "Commands/ChassisTankDrive.h"
#include "Commands/Compress.h"
#include "Commands/IntakeMaintain.h"
#include "Commands/IntakeOuttake.h"
#include "Commands/IntakeSwitchRoller.h"
#include "Commands/IntakeSwitchSolenoid.h"
#include "Commands/Shift.h"
#include "Commands/ShooterEngage.h"
#include "Commands/ShooterManualWinch.h"
#include "Commands/ShooterShoot.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driver = new Joystick(1);
	
	driverRStick = new JoystickButton(driver, 10);
	driverRStick->WhenPressed(new Shift());
	driverStart = new JoystickButton(driver, 8);
	driverStart->WhenPressed(new ChassisReverseDrive());
	coDriver = new Joystick(2);
	
	coDriverRBumper = new JoystickButton(coDriver, 6);
	coDriverRBumper->WhenPressed(new IntakeSwitchSolenoid());
	coDriverButtonX = new JoystickButton(coDriver, 3);
	coDriverButtonX->WhileHeld(new IntakeOuttake());
	coDriverButtonA = new JoystickButton(coDriver, 1);
	coDriverButtonA->WhenPressed(new IntakeSwitchRoller());
     
        // SmartDashboard Buttons
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	coDriverRThrottle = new ThrottleButton(coDriver, 3, -0.75, ThrottleButton::kNegative);
	coDriverRThrottle->WhenPressed(new ShooterShoot());
	coDriverRThrottle->WhenReleased(new ShooterEngage());
	coDriverLThrottle = new ThrottleButton(coDriver, 3, 0.75);
	coDriverLThrottle->WhenPressed(new ArmPivotSwitch());
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getDriver() {
	return driver;
}
Joystick* OI::getCoDriver() {
	return coDriver;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
