#include <stdio.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "timer/timer.h"

int main()
{
    int run = 1;
    char choice;

    while (run == 1)
    {
        displayMenu();
        choice = getchar();
        switch (choice)
        {
            case '1':
                menuCreateContact();
                break;
            case '9':
                run=0;
                break;
        }
    }
    return 0;
}
