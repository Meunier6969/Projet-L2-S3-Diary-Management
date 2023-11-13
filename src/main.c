#include <stdio.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "timer/timer.h"

int main()
{
    int run = 1;
    int choice = 0;

    while (run == 1)
    {
        displayMenu();
        choice = getInput();
    }
    
    return 0;
}
