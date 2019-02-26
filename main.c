#include <kipr/botball.h>

void drive_forward(int distance); // distance in cm 
void turn_right(int degrees);   
void turn_left(int degrees);
void drive_back(int distance);
void open_and_close_claw(int position);
void lift_and_lower_claw(int position);
void rotate_claw(int position);
void curve_drive(int distance);

    
int main()
{

//0-15 sec Pick up Gas Valve
lift_and_lower_claw(1604);
open_and_close_claw(1024);
rotate_claw(1501);
drive_forward(22); //Walk forward 9IN
msleep(500);
turn_right(90); //Turn left 90
msleep(500);
lift_and_lower_claw(0);//Lower claw 
rotate_claw(1865);
drive_forward(57); //parallel to pipe
open_and_close_claw (83);//Open claw
//walks to pvc pipe 
msleep(500);
turn_left(90); 
msleep(500);
drive_forward(38);//17in UP TO PVC PIPE
open_and_close_claw (1350);//Close claw
drive_forward(1);
slow_servo_lift(1200);//Raise claw
drive_forward(3);
lift_and_lower_claw(1600);


//15-30 sec  Drop valve and RU off at UZ
   	drive_back(20);//Walk backward 6 cm
     msleep(250);
    turn_right(90);
     msleep(500);
    drive_forward(12);
    msleep(600);
    turn_left(90);
    msleep(500);
     drive_back(60);//push water reclamation unit into UZ
  	drive_forward(25);
    lift_and_lower_claw(1700);
      msleep(700);
    turn_right(90);
      msleep(500);
    drive_back(27);
      msleep(700);
    turn_right(90);
      msleep(700);
	drive_forward(34);//drive towards PVC handle
    msleep(1500);
    lift_and_lower_claw(1400);
   cmpc(0);
    cmpc(3);

//30-45 sec //Connect Power lines
drive_back(46);//Back up 1.5 ft 
turn_left(90);//Turn left 
drive_forward(int distance); //Walk forward 
lift_and_lower_claw(int position);//Claw up(servos) 
motor (0,-20);
motor (3,50); //Slowly turn lego to bring magnet towards post
	msleep(1000)
	ao();
drive_back(int distance)//Back up
turn_right (180); //Turn 180
//Lower flat arm

//45-60 sec //Push Supplies to DRZ
drive_forward(15); //Walk forward .5ft/15 cm
turn_left(90);//Turn left collecting food and medical supplies
drive_forward(int distance); //Walk forward pushing supplies in
turn_right (180); //Turn 180 

//60-75 sec //Collect more supplies
drive_forward(46); //Walk forward 
turn_left(90);//Turn 90 left
drive_forward(30); //walk forward 
turn_left(90);//Turn 90 left collecting more supplies 
drive_forward(30); //walk forward

//75-90 sec Continue to push supplies to DRZ
turn_right (180); //Turn 180 
drive_forward(int distance); //Walk forward
turn_left(90);//Turn 90 left
drive_forward(int distance); //walk forward 
turn_left(90);//Turn 90 left
drive_forward(int distance); //walk forward pushing last of citizens into DRZ

//90-105 sec Rescue people from skybridge
turn_right (180); //turn 180
lift_and_lower_claw(int position);//lift claw
open_and_close_claw (1024);//open claw
	while(digital(8)==0) //while bump sensor is not pushed; 
	{
		drive_forward(1); //walk forward to skybridge (bump sensor)
		msleep(500)
	}
ao();
open_and_close_claw (int);//close claw 
turn_right (180); //turn 180 
drive_forward(int distance); //walk to DRZ
open_and_close_claw (1024);//open claw

//105-120 sec Repeat
	while(digital(8)==0) //while bump sensor is not pushed; 
	{
		drive_forward(1); //walk forward to skybridge (bump sensor)
		msleep(500)
	}
ao();
open_and_close_claw (int);//close claw
turn_right (180); //turn 180
drive_forward(int distance); //walk to DRZ
open_and_close_claw (1024);//open claw


    
  return 0;  
}
	    
Void drive_forward(int distance)
{
    cmpc(0);
    While (gmpc(0)<(distance*(1400/17))) //distance*(ticks/cm)
     {
         motor(0,50)
         motor(3,50)
      }
    ao();
}
void turn_left(int degrees)
{ cmpc(0);
while (abs(gmpc(0)<(abs(degrees*(1000/90)))))
    {
        mav(0,1000);
        mav(3,-1000);
        msleep(10);
    }
    cmpc(0);
    ao();
  }
void turn_right(int degrees)
{ cmpc(3);
while (abs(gmpc(3)<(abs(degrees*(1000/98)))))
    {
        mav(0,-1000);
        mav(3,1000);
        msleep(10);
    }
 cmpc(3);
 ao();
  }
void drive_back(int distance)  //input in cm
{
    cmpc(0);
    while(gmpc(0)<(distance*(-1400/17)))
    {
         motor(0,-50);
         motor(3,-50);
     }
    ao();
}
 void open_and_close_claw (int position)
{
    enable_servos();
    set_servo_position(2, position);
       msleep(1000);
   
}

void lift_and_lower_claw(int position)
{
    enable_servos();
    set_servo_position(0, position);
       msleep(1000);
}


void rotate_claw(int position)
{
    enable_servos();
    set_servo_position(1, position);
       msleep(1000);
   
}
void curve_drive(int distance)
{
    cmpc(0);
    while(gmpc(0)<(distance*(-1400/17)))
    {
	mav(0, 750);
	mav(3,500);
    }
    ao();
}


