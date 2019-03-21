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
 
{  //FIRST THINGS FIRST

	wait_for_light(0);
    shut_down_in(119);
    //NOW GO
 
     lift_and_lower_claw(1600);
    open_and_close_claw(1024);
    rotate_claw(1024);
    drive_forward(20); //Walk forward 9IN
    msleep(500);
	turn_right(95); //Turn left 90
 	msleep(700);
 	back_bump(); //parallel to pipe
   drive_back(25);
      
    //walks to pvc pipe 
    msleep(500);
	turn_left(90); 
    msleep(500);
    open_and_close_claw (90);//Open claw
    rotate_claw(1272);
    back_bump();//17in UP TO PVC PIPE
    drive_back(20);
    lift_and_lower_claw(50);//Lower claw 
    drive_forward(6);
    open_and_close_claw (1350);//Close claw
 	slow_servo_lift(1600);//Raise claw
    drive_forward(3);
	back_bump();
    
    //push water reclamation unit into UZ
    drive_back(20);//Walk backward 6 cm
    msleep(250);
    turn_right(90);
    msleep(250);
    back_bump();
    drive_back(6);
    msleep(250);
    turn_left(90);
    msleep(350);
    drive_back(57);
    
    //drive away
   drive_forward(10);
    msleep(250);
    turn_right(90);
    msleep(250);
    back_bump();
    drive_back(2);
    msleep(250);
    turn_right(100);
    msleep(250);
    rotate_claw(1434);
    lift_and_lower_claw(0);
    open_and_close_claw(83);
    lift_and_lower_claw(1554);
    open_and_close_claw(1024);
    rotate_claw(180);
    turn_left(90);
    
//get those supplies!
    back_bump();
    drive_back(6);
    turn_left(90);
    drive_forward(20);
    turn_right(90);
    back_bump();
    drive_back(90);
    turn_left(22);
    drive_back(5);
    turn_left(45);
    drive_back(5);
    turn_left(20);
    drive_back(30);
    return 0;
}
void drive_forward(int distance)
{
    cmpc(0);
    while (gmpc(0)<((distance*1400)/17)) //distance times ticks per cm
    {
   		mav(0,990);
        mav(3,800);    
    }
    ao();
    cmpc(0);
}

void turn_right(int degrees)
{ 
    cmpc(3);
    cmpc(0);
	while (abs(gmpc(3)<(abs(degrees*10))))
    {
        mav(0,-350);
        mav(3,420);
        msleep(10);
    }
    cmpc(3);
    cmpc(0);
    ao();
}
void turn_left(int degrees)
{ 
    cmpc(0);
	while (abs(gmpc(0)<(abs(degrees*10.5))))
    {
        mav(0,420);
        mav(3,-350);
        msleep(10);
    }
    cmpc(0);
    ao();
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
        mav(0,-990);
        mav(3,-800);
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
              mav(0,990);
              mav(3,800);
        }
    }
    ao();  
}

void reset_megatron()
{
    lift_and_lower_claw(1600);
    open_and_close_claw(1024);
    rotate_claw(1024);
    ao();
}
    
    
    
    
    
    
    
    
    
    

