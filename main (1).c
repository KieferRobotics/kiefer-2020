#include <kipr/wombat.h>
#include <drive_forward.h>
#include <turn_left.h>
#include <turn_right.h>
#include <drive_back.h>
#include <follow_black_ramp.h>
#include <follow_black_line.h>
#include <follow_black_platform.h>
#include <follow_black_back.h>
#include <lift_rise.h>

#define l 1
#define r 0
#define lift 3
#define ticks_traveled_ramp 4000
#define ticks_traveled 2000
#define ticks_traveled_platform 1000
#define ticks_traveled_back 2000
#define grey 2800

#define right_ref 5
#define left_ref 0

//out servo 500

int main()
{
    printf("hola mundo\n");

    enable_servos();

    set_servo_position(1,1747);
    msleep(1000);

    cmpc(0);
    cmpc(1);
    while (gmpc(0) < 7500)//follow pvc for # of ticks
    {
        if (analog(1) < 2900)//to far
        {
            mav(r,1000);//turn left
            mav(l,800);
        }
        else//to close
        {
            mav(r,800);//turn right
            mav(l,1000);
        }
    }
    ao();



    msleep(500);
    //get coupler

    set_servo_position(1,657);//servo down
    msleep(1000);

    drive_back();
    msleep(4500);

    ao();
    msleep(500);

    set_servo_position(1,1747);//servo up
    msleep(1000);

    cmpc(0);
    cmpc(1);
    while (gmpc(0) < 5000)//follow pvc for # of ticks
    {
        if (analog(1) < 2900)//to far
        {
            mav(r,1000);//turn left
            mav(l,800);
        }
        else//to close
        {
            mav(r,800);//turn right
            mav(l,1000);
        }
    }
    ao();
    msleep(500);

    cmpc(0);
    cmpc(1);
    while (gmpc(0) < 1000)//drive straight
    {
        if (gmpc(r) < gmpc(l))//to close
        {
            mav(r,1000);//turn left
            mav(l,800);
        }
        else//to far
        {
            mav(r,800);//turn right
            mav(l,1000);
        }
    }
    ao();

    //lines up with ramp
    turn_left();
    msleep(3500);

    //follow black line up the ramp

    follow_black_ramp();

    turn_left();
    msleep(2500);

    follow_black_platform();

    //grab botguy
    enable_servos();

    set_servo_position(0,488);
    msleep(1000);//open servo

    lift_rise();
    ao();
    msleep(500);

    drive_forward();
    msleep(4000);
    ao();
    msleep(500);

    set_servo_position(0,1506);//close claw
    msleep(1000);

    drive_back();
    msleep(3500);


    return 0;
}