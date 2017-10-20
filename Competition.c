#pragma config(Motor,  port1,           leftFront,     tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           leftBack,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rightBack,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           Motor5,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Motor6,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           Motor7,        tmotorVex393_MC29, openLoop)




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
	motor[rightBack] = speed;
	wait1Msec(duration);
	motor[rightFront] = 0;
	motor[leftFront] = 0;
	motor[rightBack] = 0;
	motor[rightBack] = 0;
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
	wait1Msec(duration);
	motor[Motor5] = 0;
	motor[Motor6] = 0;
}
//opens and closes the claw. Antara's Idea.
void crab (int speed, int duration) {
	motor[Motor7] = speed;
	wait1Msec(duration);
}


task main()
{

	//Plan A Autonomous

	drivestraight(90, 200);
	pointturn(75, 300);
	drivestraight(75, 200);
	crab(60, 500);
	crab(20,0);
	lift(50, 400);
	lift(20, 0);
	driveside(75, 500);
	drivestraight(90, 700);
	lift(75, 800);
	drivestraight(60, 150);
	lift(-75, 600);
	crab(-60, 400);
	crab(0,0);
	//end of first cone

	drivestraight(-90, 600);
	lift(-75, 200);
	pointturn(-75, 350);
	drivestraight(50, 100);
	crab(60, 500);
	crab(20,0);
	drivestraight(-50, 100);
	pointturn(75, 350);
	drivestraight(90, 450);
	lift(75, 700);
	drivestraight(75, 150);
	lift(-75,500);
	crab(-60, 400);
	crab(0,0);
	//end of second cone

	drivestraight(-60, 150);
	lift(-75, 200);
	crab(80, 400);
	crab(50, 0);
	lift(60, 500);
	lift(20, 0);
	drivestraight(-75, 1200);
	pointturn(75, 1000);
	drivestraight(75, 500);
	lift(-65, 400);
	crab(-80, 300);
	//End of mobile goal scoring


}
