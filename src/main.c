#include <stdio.h>
#include <stdlib.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "timer/timer.h"

void test()
{
    t_d_date date = {1,2,3};
    t_d_length len = {4, 5};

    t_d_appointment* woo = createAppointment(date, len, len, "woddo");

    t_d_appointment* next1 = createAppointment(date, len, len, "wsdadsdaso");
    t_d_appointment* next2 = createAppointment(date, len, len, "chillng");
    t_d_appointment* next3 = createAppointment(date, len, len, "bing");

    addNextAppointment(woo, next1);
    addNextAppointment(woo, next2);
    addNextAppointment(woo, next3);

    showApp(woo);
    
    fflush(stdin);
    while( getchar() != '\n' );
}

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
