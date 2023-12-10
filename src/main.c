#include <stdio.h>
#include <stdlib.h>

#include "../includes/contactinfo.h"
#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "timer/timer.h"

t_d_calendar* Calendar;

int main()
{
    Calendar = createCalendar(4);
    char choice;

    int run = 1;
    while (run)
    {
        displayMenu();
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                t_d_calcontact* newContact;
                newContact = menuCreateContact();
                insertCalContact(&Calendar, newContact);
                // Name and Surname are broken, key isn't somehow ?
                break;
            case '2':
                menuCreateAppointment();
                break;
            case '3':
                menuSeeAllContacts(Calendar);
                break;
            case '4':
                menuSearchContact();
                break;
            case '5':
                menuDeleteContact();
                break;
            case '6':
                menuDeleteAppointment();
                break;
            case '7':
                menuSaveFile();
                break;
            case '8':
                menuLoadFile();
                break;
            case '9':
                menuInfo();
                break;
            case 'q':
                run=0;
                break;
        }
    }
    printf("Thank You !\n");
    return 0;
}
