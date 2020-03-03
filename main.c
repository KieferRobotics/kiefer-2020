#include <kipr/wombat.h>
#include <servo_grab.h>
#include <servo_swing.h>
#include <servoarm.h>

thread wave;
int gray = 800;
int main()
{
    printf("Hello World\n");

    //wait for light

    //shut down in 2 minutes
    shut_down_in(118);

    //drive straight
    mav(3,800);
    mav(0,800);
    msleep(1800);
    
    //turn left 
    mav(3,0);
    mav(0,1000);
    msleep(2000);

    //follow blackline
    clear_motor_position_counter(0);
    while(get_motor_position_counter(0)<5300)
    {
        if(analog(0)>gray)
        {
            mav(0,400);
            mav(3,800);
        }
        else
        {
            mav(0,800);
            mav(3,400);
        }
    }
    
    //pause
    mav(3,0);
    mav(0,0);
    msleep(400);
    
    //turn right
    mav(3,400);
    mav(0,-800);
    msleep(1800);
    
    //drive straight
    mav(3,-800);
    mav(0,-800);
    msleep(3100);
    
    //pause
    mav(3,0);
    mav(0,0);
    msleep(200);
    
    //turn left
    mav(3,-400);
    mav(0,1000);
    msleep(1650);
    
    //pause
    mav(3,0);
    mav(0,0);
    msleep(200);
    
    //drive straight
    mav(3,-800);
    mav(0,-800);
    msleep(6000);

    //drive back
    mav(3,800);
    mav(0,800);
    msleep(200);
    
    //pause
    mav(3,0);
    mav(0,0);
    msleep(200);
    
    //open claw
    enable_servos();
    set_servo_position(2,428);
    msleep(200);
    
    //turn arm
    set_servo_position(1,1122);
    msleep(200);
    
    //pause
    mav(0,0);
    mav(3,0);
    msleep(200);
    
    //turn right
    mav(3,1000);
    mav(0,0);
    msleep(2100);
    
    //pause
    mav(3,0);
    mav(0,0);
    msleep(200);
    
    wave = thread_create(servoarm);
    thread_start(wave);
    
    mav(0,800);
    mav(3,800);
    msleep(5800);
    
    thread_destroy(wave);
    
    //close claw
    set_servo_position(2,1200);
    msleep(200);
    
    //drive back
    mav(3,-800);
    mav(0,-800);
    msleep(1800);
    
    //turn arm
    
    

        return 0;
    }
