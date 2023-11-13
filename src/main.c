#include <stdio.h>
<<<<<<< HEAD:src/main.c

#include "../includes/calendar.h"
#include "../includes/menu.h"
=======
#include <stdlib.h>
#include "contact.h"
#include "menu.h"

>>>>>>> 32094081111709b6165e95b854586a7d1762dc07:main.c
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
        }
    }
    return 0;
}
