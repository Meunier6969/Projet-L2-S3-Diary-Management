#include <stdio.h>
#include <stdlib.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "../includes/timer.h"

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
                insertCalContact(&Calendar, newContact);  //Need fixin' ?
                break;
            case '2':
                menuCreateAppointment(Calendar);
                break;
            case '3':
                menuSeeAllContacts(Calendar);
                break;
            case '4':
                menuSearchContact(Calendar);
                break;
            case '5':
                menuDeleteContact(&Calendar);
                break;
            case '6':
                menuDeleteAppointment();
                break;
            case '7':
                menuSaveFile(Calendar);
                break;
            case '8':
                menuLoadFile(&Calendar);
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
