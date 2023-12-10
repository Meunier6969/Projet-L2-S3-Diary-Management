#include <stdio.h>
#include <stdlib.h>

#include "../includes/contactinfo.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "timer/timer.h"

void test()
{
    t_d_contact* name = createContact("BING", "CHILLING");

    t_d_contactinfo* my_darling = createInfo(*name);

    t_d_date date = createDate(9, 12, 2023);
    t_d_length len = createLength(18, 35);
    t_d_appointment* woo = createAppointment(date, len, len, "現在我有冰淇淋");
    t_d_appointment* woo1 = createAppointment(date, len, len, "fgbd1");
    t_d_appointment* woo2 = createAppointment(date, len, len, "adsf2");

    // addNextAppointment(&my_darling->firstAppointment, woo);
    // addNextAppointment(&my_darling->firstAppointment, woo1);
    // addNextAppointment(&my_darling->firstAppointment, woo2);

    // displayInfoShort(my_darling);
    displayInfo(my_darling);
    deleteAppointment(&my_darling->firstAppointment, 1);
    // displayInfo(my_darling);

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
