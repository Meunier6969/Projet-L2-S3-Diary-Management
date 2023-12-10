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

    // displayInfo(c1->contact);

    insertCalContact(&cal, createCalContact(createInfo(*createContact("nassim", "a"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("antoine", "m"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("amar", "k"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("bastien", "m"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("antoine", "l"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("baptiste", "f"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("jaaard", "z"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("jaafar", "m"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("jea", "bing"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("rob", "ert"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("bob", "b"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("jean", "j"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("pierre", "p"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("bois", "b"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("frédo", "f"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("silvain", "s"))));
    insertCalContact(&cal, createCalContact(createInfo(*createContact("jaafarus", "virus"))));

    showCalendar(cal);

    printf("it runs!");
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
    return 0;
}
