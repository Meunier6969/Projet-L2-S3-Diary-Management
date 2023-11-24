#ifndef _INCLUDE_LIST
#define _INCLUDE_LIST

#include "cell.h"

// Structure of a list.
typedef struct s_d_list
{
    t_d_cell **heads;
    int nbLevels;
} t_d_list; 

// Part 1
t_d_list createEmptyList(int nbLevels);
int insertCellAtHead(t_d_list *list, int value, int levels);
int displayLevel(t_d_list list, int level);
void displayAllLevels(t_d_list list);
void displayAlign(t_d_list list); 
void insertInOrder(t_d_list *list, int value, int level);

// Part 2
t_d_list createExampleList(int n);
t_d_cell *searchClassic(t_d_list list, int value);
t_d_cell *searchHigh(t_d_list list, int value);

#endif