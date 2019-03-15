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
void GET_ON_THE_PIPE();
int main()
 
{  //FIRST THINGS FIRST


    shut_down_in(119);
    //NOW GO
 
     lift_and_lower_claw(1800);
    open_and_close_claw(1024);
    rotate_claw(180);
    drive_forward(20); //Walk forward 9IN
    msleep(500);
	turn_right(95); //Turn left 90
 	msleep(700);
 	drive_forward(60); //parallel to pipe
   
       //walks to pvc pipe 
    msleep(500);
	turn_left(90); 
    msleep(500);
    open_and_close_claw (90);//Open claw
    rotate_claw(1227);
    back_bump();//17in UP TO PVC PIPE
    drive_back(20);
    lift_and_lower_claw(665);//Lower claw 
    drive_forward(6);
    open_and_close_claw (1350);//Close claw
 	slow_servo_lift(1600);//Raise claw
    drive_forward(3);
	back_bump();
    
    //WALKS TOWARDS OTHER SIDE
   	drive_back(15);//Walk backward 6 cm
    rotate_claw(180);
    msleep(250);
    turn_right(90);
    msleep(500);
    back_bump();
    msleep(500);
    drive_back(6);
    slow_rotate_left(1500);
    back_bump();
    msleep(250);
    turn_left(90);
    msleep(500);
    drive_back(52);//push water reclamation unit into UZ
    drive_forward(10);//drive away
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
    
//insert power lines 
    back_bump();
    drive_back(6);
    turn_left(90);
    drive_forward(20);
    turn_right(90);
    drive_back(100);
    turn_left(22);
    drive_back(3);
    turn_left(45);
    drive_back(30);
    return 0;
}

void drive_forward(int distance)
{
    cmpc(0);
    while (gmpc(0)<((distance*1400)/17)) //distance times ticks per cm
    {
         mav(0,800);
         mav(3,737);       
    }
    ao();
    cmpc(0);
}

void turn_right(int degrees)
{ 
    cmpc(3);
    cmpc(0);
	while (abs(gmpc(3)<(abs(degrees*10.5))))
    {
        mav(0,-200);
        mav(3,300);
        msleep(10);
    }
    cmpc(3);
    cmpc(0);
    ao();
}
void turn_left(int degrees)
{ 
    cmpc(0);
	while (abs(gmpc(0)<(abs(degrees*10))))
    {
        mav(0,300);
        mav(3,-200);
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
              mav(0,800);
              mav(3,760);
        }
    }
    ao();  
}

void GET_ON_THE_PIPE()
{
            
    int x=0;
    int y=2;
    int counter=0;
    while (counter<6)

    {
        slow_servo_lift(x);
        msleep(50);
        x+=25;
        drive_back(3);
        slow_servo_open(y);
        y+=3;
        counter+=1;
    }
ao();
}



