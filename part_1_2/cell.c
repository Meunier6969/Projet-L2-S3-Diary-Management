#include <stdlib.h>
#include <stdio.h>
#include "cell.h"

t_d_cell* createCell(int value, int height)
{
    t_d_cell* newCell = (t_d_cell*) malloc(sizeof(t_d_cell));

    newCell->value = value;
    newCell->nbLevels = height;
    newCell->next = (t_d_cell**) calloc(height, sizeof(t_d_cell*));

    return newCell;
}

void displayCell(t_d_cell cell)
{
    printf("(%d), ", cell.value);
    for (size_t i = 0; i < cell.nbLevels; i++)
    {
        printf("[%p] ", cell.next[i]);
    }
}