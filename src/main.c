#include <stdio.h>
#include <stdlib.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "timer/timer.h"

int main()
{
    int run = 1;
    char choice;
    while (run == 1)
    {
        displayMenu();
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '0':
                char out;
                char* name;
                name = scanString(30);

                t_d_contact *bing = createContact(name, "Chilling");
                t_d_calendar* cal = createCalendar(*bing);

                displayCalendar(cal);
                deleteCalendar(&cal);
                deleteContact(bing);
                scanf("%c", &out);
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
