#include <kipr/botball.h>

void drive_forward(int distance); // distance in cm 
void turn_right(int degrees);   
void turn_left(int degrees);
void drive_back(int distance);
void open_and_close_claw(int position);
void lift_and_lower_claw(int position);
void rotate_claw(int position);

    
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
turn_right (180); //Turn 180
//Lower flat arm

//45-60 sec //Push Supplies to DRZ
drive_forward(int distance); //Walk forward .5 ft.
turn_left(int degrees);//Turn left collecting food and medical supplies
drive_forward(int distance); //Walk forward pushing supplies in
turn_right (180); //Turn 180 

//60-75 sec //Collect more supplies
drive_forward(int distance); //Walk forward 
turn_left(int degrees);//Turn 90 left
drive_forward(int distance); //walk forward 
turn_left(int degrees);//Turn 90 left collecting more supplies 
drive_forward(int distance); //walk forward

//75-90 sec Continue to push supplies to DRZ
turn_right (180); //Turn 180 
drive_forward(int distance); //Walk forward
turn_left(int degrees);//Turn 90 left
drive_forward(int distance); //walk forward 
turn_left(int degrees);//Turn 90 left
drive_forward(int distance); //walk forward pushing last of citizens into DRZ

//90-105 sec Rescue people from skybridge
turn_right (180); //turn 180
lift_claw(int);//lift claw 
open_claw (int);//open claw 
drive_forward(int distance); //walk forward to skybridge (bump sensor)
close_claw (int);//close claw 
turn_right (180); //turn 180 
drive_forward(int distance); //walk to DRZ 
open_claw (int);//open claw

//105-120 sec Repeat 
drive_forward(int distance); //walk forward to skybridge (bump sensor)
close_claw (int);//close claw 
turn_right (180); //turn 180 
drive_forward(int distance); //walk to DRZ 
open_claw (int);//open claw


    
  return 0;  
}
	    
Void drive_forward(int distance)
{
    cmpc(0);
    While (gmpc(0)<(distance*(1400/17))) //distance*ticks/cm)
     {
         motor(0,50)
         motor(3,50)
      }
    ao();
}
void turn_right(int degrees)
{
    cmpc(0);
    While (abs(gmpc(0)<(distance*(1000/90)))) //distance*(ticks/degree)
    {
    motor(0,50);
    motor(3,-50);
    }
    ao();
}
void turn_left(int degrees)
{

    cmpc(0);
    while(abs(gmpc(0)<(degrees*(1000/90)))) //distance*(ticks/degree)
    {
    motor(0,-50);
    motor(3,50);
    }
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

