#include <stdio.h>
#include <stdlib.h>

#include "../includes/contactinfo.h"
#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "timer/timer.h"

void test()
{
    t_d_calendar* cal = createCalendar(4);

    t_d_calcontact* c1 = createCalContact(createInfo(*createContact("fuck", "you")));

    insertCalContact(cal, c1);

    showCalendar(cal);

    scanf("\n");
}

int main()
{
    int run = 1;
    char choice;
    while (run)
    {
        displayMenu();
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '0':
                test();
                break;

            case '1':
                menuCreateContact();
                break;
            case '2':
                menuCreateAppointment();
                break;
            case '3':
                menuSearchContact(); 
                break;
            case '4':
                menuSaveFile();
                break;
            case '5':
                menuLoadFile();
                break;
            case '6':
                menuInfo();
                break;
            case '7':
                run=0;
                break;
        }
    }
    return 0;
}
