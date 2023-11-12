#include <stdio.h>

#include "calendar.h"
#include "menu.h"
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
