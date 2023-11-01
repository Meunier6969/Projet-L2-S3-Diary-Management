#include <stdlib.h>
#include <stdio.h>

#include "list.h"

t_d_list createEmptyList(int nbLevels)
{
    t_d_list list;
    
    list.nbLevels = nbLevels;
    list.heads = (t_d_cell**) calloc(nbLevels, sizeof(t_d_cell*));

    return list;
}

void insertCellAtHead(t_d_list *list, int value, int levels)
{
    // Plus Tard
}

int displayLevel(t_d_list list, int level)
{
    if (level > list.nbLevels || level < 0)
    {
        printf("Can't display a level that doesn't exist.");
        return 1;
    }
    
    // [list head : 0] -> [69] -> NULL

    printf("[list head : %d] -> ", level);
    t_d_cell *current = list.heads[level];

    while (current != NULL)
    {
        printf("[%d] -> ", current->value);
        current = current->next[level];
    }
    
    printf("NULL\n");

    return 0;
}

void displayAllLevels(t_d_list list)
{
    for (size_t i = 0; i < list.nbLevels; i++)
        displayLevel(list, i);
}