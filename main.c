#include <kipr/botball.h>

void drive_forward(int distance); // distance in cm 
void turn_right(int degrees);   
void turn_left(int degrees);
void drive_back(int distance);
void open_claw(int );
void close_claw(int);
void lift_claw(int);
void lower_claw(int);


    
int main()
{

//0-15 sec Pick up Gas Valve
drive_forward(int distance); //Walk forward 2 ft
turn_left(90); //Turn left 90B0
drive_forward(int distance); //Walk forward 2.5 ft to gas valve
open_claw (int);//Open claw
lower_claw(int);//Lower claw onto valve
close_claw (int);//Close claw
lift_claw(int);//Raise claw
drive_back(int distance)//Walk backward 0.5 ft
turn_right(180);   //Turn right 180B0

//15-30 sec  Drop valve and RU off at UZ
drive_forward(int distance); //Walk to 2.5 ft to UZ and push RU inside of it
lower_claw(int);//Lower claw to align with PVC
turn_left(45);//Turn left 45B0
drive_forward(int distance); //Walk forward 0.25 ft
turn_right(45);   //Turn right 45B0
open_claw (int);//Open claw to let go of valve

//30-45 sec //Connect Power lines
drive_back(int distance);//Back up 1.5 ft 
turn_left(90);//Turn left 
drive_forward(int distance); //Walk forward 
lift_claw(int);//Claw up (servos) 
motor (0,-20);
motor (3,50); //Slowly turn lego to bring magnet towards post
drive_back(int distance)//Back up
turn_around (180); //Turn 180
//Lower flat arm

//45-60 sec //Push Supplies to DRZ
drive_forward(int distance); //Walk forward .5 ft.
turn_left(int degrees);//Turn left collecting food and medical supplies
drive_forward(int distance); //Walk forward pushing supplies in
turn_around (180); //Turn 180 

//60-75 sec //Collect more supplies
drive_forward(int distance); //Walk forward 
turn_left(int degrees);//Turn 90 left
drive_forward(int distance); //walk forward 
turn_left(int degrees);//Turn 90 left collecting more supplies 
drive_forward(int distance); //walk forward

//75-90 sec Continue to push supplies to DRZ
turn_around (180); //Turn 180 
drive_forward(int distance); //Walk forward
turn_left(int degrees);//Turn 90 left
drive_forward(int distance); //walk forward 
turn_left(int degrees);//Turn 90 left
drive_forward(int distance); //walk forward pushing last of citizens into DRZ



//90-105 sec Rescue people from skybridge
turn_around (180); //turn 180
lift_claw(int);//lift claw 
open_claw (int);//open claw 
drive_forward(int distance); //walk forward to skybridge (bump sensor)
close_claw (int);//close claw 
turn_around (180); //turn 180 
drive_forward(int distance); //walk to DRZ 
open_claw (int);//open claw

//105-120 sec Repeat 
drive_forward(int distance); //walk forward to skybridge (bump sensor)
close_claw (int);//close claw 
turn_around (180); //turn 180 
drive_forward(int distance); //walk to DRZ 
open_claw (int);//open claw


    
  return 0;  
}


void drive_forward(int distance) //input in cm
{
    motor(0,50);
    motor(2,50);
    msleep(distance/50*100); //time = distance/vel times 1000 in ms
    ao();
}
void turn_right(int degrees)
{
    motor(0,50);
    motor(2,-50);
    msleep(degrees*20); //need to figure out number of degrees per ms
    ao();
}
void turn_left(int degrees)
{
    motor(0,-50);
    motor(2,50);
    msleep(degrees*20); //figure out degrees per ms
}
void drive_back(int distance
{
	motor(0,-50)
    motor(2,-50)
    msleep(distance*1400/17)
}
void open_claw(int)
{
    enable_servos();
    set_servo_position(0,position)
    disable_servos();
}
void close_claw(int position)
{
    enable_servos
    