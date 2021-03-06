#pragma config(Sensor, dgtl2,  bumper,         sensorTouch)
#pragma config(Motor,  port1,           Motor5,        tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           leftFront,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           DoNotYouDare,  tmotorNone, openLoop)
#pragma config(Motor,  port7,           Motor7,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           Motor8,        tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           Motor9,        tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          Motor6,        tmotorVex393HighSpeed_HBridge, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include  "Shared/Competition.h"

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//#BUILTBYGIRLS
float multiplier = 1.0;

void drivestraight (int speed, int duration) {
	motor[rightFront] = speed;
	motor[leftFront] = speed;
	motor[rightBack] = speed;
	motor[leftBack] =  speed;
	wait1Msec(duration);
	motor[rightFront] = 0;
	motor[leftFront] = 0;
	motor[rightBack] = 0;
	motor[leftBack] = 0;
}

void driveside (int speed, int duration) {
	motor[rightFront] = speed;
	motor[leftFront] = -speed;
	motor[rightBack] = -speed;
	motor[leftBack] = speed;
	wait1Msec(duration);
	motor[rightFront] = 0;
	motor[leftFront] = 0;
	motor[rightBack] = 0;
	motor[leftBack] = 0;
}
void pointturn (int speed, int duration) {
	motor[rightFront] = speed;
	motor[leftFront] = -speed;
	motor[rightBack] = speed;
	motor[leftBack] = -speed;
	wait1Msec(duration);
	motor[rightFront] = 0;
	motor[leftFront] = 0;
	motor[rightBack] = 0;
	motor[leftBack] = 0;
}

// lift the eight bar
void lift (int speed, int duration) {
	motor[Motor5] = speed;
	motor[Motor6] = speed;
	motor[Motor8] = speed;
	motor[Motor9] = speed;
	wait1Msec(duration);
	motor[Motor5] = 0;
	motor[Motor6] = 0;
	motor[Motor8] = 0;
	motor[Motor9] = 0;
}
//opens and closes the claw. Antara's Idea. :)
void crab (int speed, int duration) {
	motor[Motor7] = speed;
	wait1Msec(duration);
}

void autonMobileGoalR(){
	crab(-60,multiplier*600);
	drivestraight(70, multiplier*1800);//drive forward
	crab(60,multiplier*500);
	drivestraight(70,multiplier*950);
	crab(-70, multiplier*1000);//close claw on mobile ghoul 0_0
	motor[Motor7] = -40;//keep claw closed
	lift(70,multiplier*500);//lift slightly off the ground
	motor[Motor5] = 15;
	motor[Motor6] = 15; //keep claw lifted
	motor[Motor8] = 15;//keep claw lifted
	motor[Motor9] = 15;
	driveside(70, multiplier*500); //get away from wall
	pointturn(70, multiplier*2550); //turn left A LOT
	drivestraight(70,multiplier*3900); //drive to scoring zone
	pointturn(70, multiplier*1200);
	motor[Motor5] = 50;
	motor[Motor6] = 50; //keep claw lifted
	motor[Motor8] = 50;//keep claw lifted
	motor[Motor9] = 50;
	lift(-20,multiplier*800); //put mobile goal down
	crab(70,multiplier*700); //let go of mobile goal
	drivestraight(-70,multiplier*500); //back up
}

void autonMobileGoalL(){
	crab(-60,multiplier*600);
	drivestraight(70, multiplier*1800);//drive forward
	crab(60,multiplier*500);
	drivestraight(70,multiplier*950);
	crab(-70, multiplier*1000);//close claw on mobile ghoul 0_0
	motor[Motor7] = -40;//keep claw closed
	lift(70,multiplier*500);//lift slightly off the ground
	motor[Motor5] = 15;
	motor[Motor6] = 15; //keep claw lifted
	motor[Motor8] = 15;//keep claw lifted
	motor[Motor9] = 15;
	driveside(-70, multiplier*800/*previously 500*/); //get away from wall
	pointturn(-70, multiplier*2550); //turn right A LOT
	drivestraight(70,multiplier*3900); //drive to scoring zone
	lift(70,multiplier*700);//originally not there
	pointturn(70, multiplier*1200);
	motor[Motor5] = 50;
	motor[Motor6] = 50; //keep claw lifted
	motor[Motor8] = 50;//keep claw lifted
	motor[Motor9] = 50;
	drivestraight(70,multiplier*800);//origninally not there haha lets see how it worrrrrrkkks guyyyyyyyiiiiiessss
	lift(-20,multiplier*800); //put mobile goal down
	crab(70,multiplier*700); //let go of mobile goal
	drivestraight(-70,multiplier*500); //back up
}
//task main() {
	void autonomous() {

	if (nImmediateBatteryLevel/1000.0 >= 7.6) {
		multiplier = 0.75;
	}
	if(nImmediateBatteryLevel/1000.0 >= 7 && nImmediateBatteryLevel/1000.0 < 8){
		multiplier = 1.0;
	}
	if(nImmediateBatteryLevel/1000.0 >= 6 && nImmediateBatteryLevel/1000.0 < 7) {
		multiplier = 1.4;
	}

	autonMobileGoalR();

}



void joystick(){
while(1 == 1){
	float ratio = 1.0;
	while (vexRT[Btn5U]){ ratio = 0.7;}
	while (vexRT[Btn5DXmtr2]){ ratio = 0.6;}

	if(SensorValue[bumper] == 1) {
		//turnLEDON(greenLED);//**Error**:Undefined procedure 'turnLEDON'.
		motor[Motor5] = 0;
		motor[Motor6] = 0;
		motor[Motor8] = 0;
		motor[Motor9] = 0;
	}
	//Remote Control Commands
	motor[leftFront] = ratio * (vexRT[Ch3] + vexRT[Ch1]);
	motor[leftBack] =  ratio * vexRT[Ch3] - vexRT[Ch1];
	motor[rightFront] = ratio * vexRT[Ch2] - vexRT[Ch1];
	motor[rightBack] =  ratio * vexRT[Ch2] + vexRT[Ch1];

	//Joystick stationary goal scoring

	motor[Motor5] = ratio * vexRT[Ch3Xmtr2];
	motor[Motor6] = ratio * vexRT[Ch3Xmtr2];
	motor[Motor8] = ratio * vexRT[Ch3Xmtr2];
	motor[Motor9] = ratio * vexRT[Ch3Xmtr2];

	motor[Motor7] = vexRT[Ch1Xmtr2];//Claw
	while (vexRT[Btn6UXmtr2]){
		lift(70, 120);
		wait1Msec(500);
		lift(70,0);
		crab(-70, 700);
		wait1Msec(500);

}

}
		}
