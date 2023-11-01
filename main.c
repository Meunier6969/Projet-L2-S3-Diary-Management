#include <stdio.h>

#include "list.h"

int main()
{
    t_d_list list = createEmptyList(5);

    displayAllLevels(list);

    printf("Adding a cell\n");

    insertCellAtHead(&list, 5, 5);
    insertCellAtHead(&list, 4, 4);
    insertCellAtHead(&list, 3, 3);
    insertCellAtHead(&list, 2, 2);
    insertCellAtHead(&list, 1, 1);
    insertCellAtHead(&list, 0, 0);

    displayAllLevels(list);
    
    return 0;
}