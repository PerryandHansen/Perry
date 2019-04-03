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
void reset_megatron();
void negback_bump();
void follow_the_line(int distance);
int b=3100;

int main()
 
{  //FIRST THINGS FIRST

//	wait_for_light(0);
    shut_down_in(119);
    //NOW GO

    reset_megatron();
    msleep(500);
	turn_right(93); //Turn left 90
 	msleep(700);
    drive_forward(30);
 	back_bump(); //parallel to pipe
   msleep(500);
    turn_left(90);
    msleep(500);
  
      
    //walks to pvc pipe 
    open_and_close_claw (0);//Open claw
    rotate_claw(1200);
    msleep(500);
    lift_and_lower_claw(50);//Lower claw 
       drive_forward(8);
    back_bump();
    drive_forward(38);//17in UP TO PVC PIPE
    open_and_close_claw (1350);//Close claw
 	slow_servo_lift(1600);//Raise claw
    
    while (analog(2)<b)
    { mav(0,500);
      msleep(10);
     ao();
    }
    
    drive_back(10);
  
	
    
    //push gas valve into UZ
    negback_bump();//Walk backward UNTIL BLACK LINE
    msleep(250);
    turn_right(90);
    msleep(250);
    drive_forward(27);
    msleep(250);
    turn_right(90);
    msleep(250);
    drive_forward(15);
    back_bump();
    lift_and_lower_claw(0);
    open_and_close_claw(83);
    lift_and_lower_claw(1554);
    open_and_close_claw(1024);
    reset_megatron();
    drive_back(30);
   
    
    
//get those supplies!    
 negback_bump();
 drive_forward(7);
 msleep(250);
turn_left(90);
msleep(250);
drive_back(87);
turn_left(22);
drive_back(5);
turn_left(45);
drive_back(5);
turn_left(20);
drive_back(15);
negback_bump();
    
    
//FIREPOLE
      drive_back(5);
    turn_left(90);
    drive_forward(25);           
    back_bump();
    msleep(100);
    turn_right(185);
    msleep(100);
    negback_bump();
    drive_back(47);//57cm from inside black box to outside black tape of other box
    msleep(250);
    turn_right(90);
    msleep(250);
    drive_back(20);
    drive_forward(15);
    msleep(250);
    turn_left(90);
    msleep(250);
    drive_back(12);
    turn_left(90);
    drive_forward(10);
    turn_right(45);
    drive_back(10);
    turn_left(90);
    drive_forward(10);
    turn_right(45);
    drive_back(10);
    turn_left(90);   
    
    
    
    
  
    return 0;
}
void drive_forward(int distance)
{
    cmpc(0);
    while (gmpc(0)<((distance*1400)/17)) //distance times ticks per cm
    {
   		mav(0,976);
        mav(3,991);    
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
        mav(0,-358);
        mav(3,423);
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
        mav(0,430);
        mav(3,-355);
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
        mav(0,-920);
        mav(3,-955);
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
    while ((analog(1)<b) & (analog(2)<b))
    {
              mav(0,976);
              mav(3,991);
        }
       ao();
        if (analog(1)>b)
        {  
          while (analog(2)<b)
          {	mav(0,500);
            mav(3,0);
        }
        }
        
        if (analog(2)>b)       
        { 
           while(analog(1)<b)
           {
            mav(0,0);
            mav(3,500);
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
    
    
void negback_bump()
{ 
    { 
    while ((analog(1)<b) & (analog(2)<b))
    {
              mav(0,-976);
              mav(3,-991);
        }
       ao();
        if (analog(1)>b)
        {  
          while (analog(2)<b)
          {	mav(0,-500);
            mav(3,0);
        }
        }
        
        if (analog(2)>b)       
        { 
           while(analog(1)<b)
           {
            mav(0,0);
            mav(3,-500);
        }
        }
    
    ao();  }
}


void follow_the_line(int distance) 
{ 
    cmpc(0);
    int b=3100;
    while (gmpc(0)<((distance*1400)/17)) //distance times ticks per cm
    {
    cmpc(0);
    if (analog(1)<b)//sees less than black aka white or gray
    {
        motor(0,-70);
        motor(3,-55);
        msleep(10);
    }
    
   else 
   { 
       motor(0,-55);
       motor(3,-70);
       msleep(10);
       
   }
    }
    ao();
}
    
    
    
    
    
    

