#include <stdlib.h>
#include <stdio.h>

#include "list.h"

t_d_list createEmptyList(int nbLevels)
{
    t_d_list list;
    
    list.nbLevels = nbLevels;
    list.heads = (t_d_cell**) malloc(nbLevels * sizeof(t_d_cell*));

    for (size_t i = 0; i < nbLevels; i++)
        list.heads[i] = NULL;

    return list;
}

int insertCellAtHead(t_d_list *list, int value, int levels)
{
    if (list == NULL)
    {
        fprintf(stderr, "Can't add to an empty list");
        return 1;
    }

    if (levels < 0) levels = 0;
    if (levels >= list->nbLevels) levels = list->nbLevels;

    t_d_cell* newCell = createCell(value, levels);

    for (size_t i = 0; i < levels; i++)
    {
        newCell->next[i] = list->heads[i];
        list->heads[i] = newCell;
    }
    
    return 0;
}

// Returns 1 if the level asked is out-of-bounds, 0 otherwise
int displayLevel(t_d_list list, int level)
{
    if (level > list.nbLevels || level < 0)
    {
        fprintf(stderr, "Can't display a level that doesn't exist.");
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