#include <stdio.h>
#include <stdlib.h>

#include "../includes/contactinfo.h"
#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "timer/timer.h"

t_d_calendar* Calendar;

void test()
{
    t_d_calendar* cal = createCalendar(4);

    // displayInfo(c1->contact);

    insertCalContact(&cal, createCalContact(createInfo(createContact("antoine", "m"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("amar", "k"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("bastien", "m"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("antoine", "l"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("nassim", "a"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("baptiste", "f"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("jaaard", "z"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("jaafar", "m"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("jea", "bing"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("rob", "ert"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("bob", "b"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("jean", "j"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("pierre", "p"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("bois", "b"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("frédo", "f"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("silvain", "s"))));
    insertCalContact(&cal, createCalContact(createInfo(createContact("jaafarus", "virus"))));

    showCalendar(cal);
    printf("it runs!\n\n");
    printf("%p\n", searchCalContact(cal, "amar_k"));
    printf("%p\n", searchCalContact(cal, "jaafarus_virus"));
    printf("%p\n", searchCalContact(cal, "pierre_p"));
    printf("%p\n", searchCalContact(cal, "silvain_t"));
    printf("%p\n", searchCalContact(cal, "silvain_s"));
    printf("%p\n", searchCalContact(cal, "zzzzzz_z"));

    scanf("\n");
}

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
            case '0':
                test();
                break;
            case '1':
                t_d_calcontact* newContact;
                newContact = menuCreateContact();
                insertCalContact(&Calendar, newContact);
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
