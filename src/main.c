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

    t_d_calcontact* c1 = createCalContact(createInfo(*createContact("AA", "!")));
    t_d_calcontact* c2 = createCalContact(createInfo(*createContact("CC", "!")));
    t_d_calcontact* c3 = createCalContact(createInfo(*createContact("BB", "!")));

    // displayInfo(c1->contact);

    insertCalContact(&cal, c1);
    insertCalContact(&cal, c2);
    insertCalContact(&cal, c3);

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
                menuSeeAllContacts(); 
                break;
            case '4':
                menuSearchContact;
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
    return 0;
}
