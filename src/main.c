#include <stdio.h>
#include <stdlib.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"
#include "../includes/list.h"
#include "../includes/cell.h"
// #include "timer/timer.h"

int main()

{
    printf("Fuck antoine");
    t_d_list list = createEmptyList(5);

    displayAllLevels(list);

    printf("Adding a cell\n");

    insertCellAtHead(&list, 5, 5);
    insertCellAtHead(&list, 4, 4);
    //insertCellAtHead(&list, 3, 3);
    insertCellAtHead(&list, 2, 2);
    insertCellAtHead(&list, 1, 1);
    insertCellAtHead(&list, 0, 0);

    displayAllLevels(list);

    insertInOrder(&list, 3, 3);
    printf("\n Test pour le insert in order :\n");

    displayAllLevels(list);
    
    return 0;


    /*
    int run = 1;
    char choice;

    while (run == 1)
    {
        displayMenu();
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                menuCreateContact();
                break;
            case '2':
                menuCreateAppointment();
                break;
            case '3':
                menuDeleteAppointment();
                break;
            case '9':
                run=0;
                break;
        }
    }
    return 0;
    */
}
