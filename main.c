#include <kipr/botball.h>
void drive_forward(int distance);
void turn_right(int degrees);// distance in cm
void turn_left(int degrees);
void lift_and_lower_claw(int position);
void open_and_close_claw (int position);
void drive_back(int distance);
void rotate_claw(int position);
void curve_drive(int distance);
void slow_rotate_left(int position);
void slow_rotate_right(int position);
void slow_servo_lift(int position);
void slow_servo_lower(int position);
void slow_servo_open(int position);
void slow_servo_close(int position);
void back_bump();
    
int main()
{

//0-15 sec Pick up Gas Valve
lift_and_lower_claw(1674);
open_and_close_claw(1024);
rotate_claw(180);
drive_forward(20); //Walk forward 9IN
msleep(500);
turn_right(90); //Turn left 90
msleep(500);
rotate_claw(1434);
drive_forward(58); //parallel to pipe
open_and_close_claw (83);//Open claw
      //walks to pvc pipe 
msleep(500);
turn_left(90); 
msleep(500);
back_bump();//17in UP TO PVC PIPE
drive_back(20);
lift_and_lower_claw(550);//Lower claw 
drive_forward(6);
open_and_close_claw (1350);//Close claw
drive_forward(1);
slow_servo_lift(1600);//Raise claw
drive_forward(3);
back_bump();
  
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
open_and_close_claw(1050);//set position (level)
    msleep(500);
drive_back(33);//Back up 1.5 ft
    msleep(500);
turn_left(90);//Turn left 
    msleep(500);
drive_forward(30); //Walk forward 
    msleep(500);
slow_servo_lift(1024);//Claw up(servos)
    msleep(500);
lift_and_lower_claw(400)
    msleep(500);
drive_back(30);//Back up
    msleep(500);
turn_right(180); //Turn 180
    msleep(500);

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
	    
void drive_forward(int distance)
{
    cmpc(0);
    while (gmpc(0)<((distance*1400)/17)) //distance times ticks per cm
    {
         mav(0,900);
         mav(3,800);       
    }
    ao();
    cmpc(0);
}

void turn_right(int degrees)
{ 
    cmpc(3);
	while (abs(gmpc(3)<(abs(degrees*10))))
    {
        mav(0,-300);
        mav(3,300);
        msleep(10);
    }
    cmpc(3);
    ao();
}

void turn_left(int degrees)
{
    cmpc(0);
    cmpc(3);
	while (abs(gmpc(0)<(abs(degrees*10))))
    {
        mav(0,300);
        mav(3,-200);
        msleep(10);
    }
}

void lift_and_lower_claw(int position)//1730 HIGH 450 low
{
    enable_servos();
    set_servo_position(0, position);
    msleep(1000);
}


void slow_servo_lift(int position)
{
    enable_servos();
    int x = 0;
    while(x<position)
    {
    	set_servo_position(0, x);
        msleep(50);
        x+=25;
    }
}

void slow_servo_lower(int position)
{
    enable_servos();
    int x = 0;
    while(x<position)
    {
    	set_servo_position(0, x);
        msleep(50);
        x-=25;
    }
}

void open_and_close_claw (int position)// limit: 1500closed 600open
{
    enable_servos();
    set_servo_position(2, position);
    msleep(1000);   
}

void slow_servo_close(int position)
{
    enable_servos();
    int x = 0;
    while(x<position)
    {
    	set_servo_position(2, x);
        msleep(50);
        x+=25;
    }
}

void slow_servo_open(int position)
{
    enable_servos();
    int x = 0;
    while(x<position)
    {
    	set_servo_position(2, x);
        msleep(50);
        x-=15;
    }
}

void drive_back (int distance)
{
    cmpc(0);
    while (abs(gmpc(0))<(abs(distance*(1400/17)))) //distance times ticks per cm 
    {
         mav(0,-500);
         mav(3,-500);
    }
    ao();
    cmpc(0);
}

void rotate_claw(int position)//limit: 1800 left 600 right 
{
    enable_servos();
    set_servo_position(1, position);
    msleep(1000);
   
}

void slow_rotate_left(int position) //right is less, left is more
{
    enable_servos();
    int x = 0;
    while(x<position)
    {
    	set_servo_position(1, x);
        msleep(50);
        x+=25;
    }
}

void slow_rotate_right(int position)
{
    enable_servos();
    int x = 0;
    while(x<position)
    {
    	set_servo_position(1, x);
        msleep(50);
        x-=25;
    }
}


void curve_drive(int distance)
{
    cmpc(0);
    while(gmpc(0)<(distance*(-1400/17)))
    {
		mav(0,750);
		mav(3,500);
    }
    ao();
}

void back_bump()
{ 
    while (digital(0)==0 || digital(8)==0)
    {
       
        if (digital(8)==1)
        {  
            mav(0,1000);
            mav(3,0);
        }
        
        if (digital(0)==1)       
        { 
            mav(0,0);
            mav(3,1000);
        }
    
        else
        {
              mav(0,900);
              mav(3,900);
        }
    }
    ao();  
}


