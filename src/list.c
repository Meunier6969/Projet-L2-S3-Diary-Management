#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../includes/list.h"

// Part 1
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
        printf("[%3d] -> ", current->value);
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

void displayAlign(t_d_list list)
{
    for (int i = 0; i < list.nbLevels; i++)
    {
        printf("[head : %d] -> ", i);
        t_d_cell* current = list.heads[0];
        while (current != NULL)
        {
            if (i < current->nbLevels)
            {
                //If the cell's level matches the current display level
                printf("[%4d]", current->value);
            }
            else
            {
                //If the cell's level is greater than the current display level, print arrow
                printf("------");
            }
            printf(" -> ");
            current = current->next[0]; 
        }
        printf("NULL\n");
    }
}

// Part 2
t_d_list createExampleList(int n)
{
    t_d_list list = createEmptyList(n);
    int lenght = (int) (pow(2, n) - 1);
    int level = 0;

    for (size_t i = lenght; i > 0; i--)
    {
        // Probably not optimized but fuck itSS
        level = 1;
        for (size_t j = 1; j < n; j++)
        {
            if (i%(int)(pow(2, j)) == 0) level += 1;
        }
        
        insertCellAtHead(&list, i, level);
    }

    return list;
}

t_d_cell *searchClassic(t_d_list list, int value)
{
    if (list.heads == NULL) return NULL;

    t_d_cell* current = list.heads[0];

    do
    {
        if (current->value == value)
            return current;

        if (current->value > value)
            break;
        else
            current = current->next[0];

    } while (current != NULL);

    return NULL;
}

t_d_cell *searchHigh(t_d_list list, int value)
{
    if (list.heads == NULL) return NULL;

    int currentLevel = list.nbLevels - 1; 
    t_d_cell *current = list.heads[currentLevel];

    do
    {
        if (current->value == value)
            return current;

        if (currentLevel > 0 && current->value > value)
            current = list.heads[--currentLevel];
        else
            current = current->next[0];

    } while (current != NULL);

    return NULL;
}

void insertInOrder(t_d_list *list, int value, int level)
{
    level-=1;
    if (list == NULL || level < 0 || level >= list->nbLevels)
    {
        fprintf(stderr, "Invalid list or level");
        return;
    }

    // Special case: If the list is empty or the new value is less than the head value
    if (list->heads[0] == NULL || value < list->heads[0]->value)
    {
        // Insert at all levels up to the specified level
        for (int i = 0; i <= level; i++)
        {
            t_d_cell* newCell = createCell(value, list->nbLevels);

            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }

        return;
    }

    // Traverse the list to find the appropriate position for insertion
    for (int i = 0; i <= level; i++)
    {
        t_d_cell* current = list->heads[i];
        t_d_cell* prev = NULL;

        while (current != NULL && current->value < value)
        {
            prev = current;
            current = current->next[i];
        }

        // Insert the new cell into the appropriate position
        if (prev != NULL)
        {
            // Insert in the middle
            t_d_cell* newCell = createCell(value, list->nbLevels);
            newCell->next[i] = prev->next[i];
            prev->next[i] = newCell;
        }
        else
        {
            // Insert at the beginning
            t_d_cell* newCell = createCell(value, list->nbLevels);
            newCell->next[i] = list->heads[i];
            list->heads[i] = newCell;
        }
    }
}

