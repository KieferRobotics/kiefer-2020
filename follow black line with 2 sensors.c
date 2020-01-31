#include <kipr/botball.h>
int lfcliff_grey = 1500;
int rfcliff_grey =1500;

void straight_on_black();

int main()

{

    printf("Hello World\n");

    create_connect();
    straight_on_black();

    return 0; 
}
void straight_on_black()
{

    set_create_distance(0);
    while (get_create_distance() < 500)
    {
        if (get_create_lfcliff_amt() > lfcliff_grey) //see black
        {
            create_drive_direct(100,200);
        }
        if (get_create_lfcliff_amt() < lfcliff_grey) //sees white
        {
            create_drive_direct(200,100);
        }
        if (get_create_rfcliff_amt() > rfcliff_grey) //see black
        {
            create_drive_direct(100,200);
        }
        if (get_create_rfcliff_amt() < rfcliff_grey) //sees white
        {
            create_drive_direct(200,100);
        }
        else
        {
            create_drive_direct(100,100);
        }
    }
    create_stop();
}




