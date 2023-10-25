#ifndef _INCLUDE_LIST
#define _INCLUDE_LIST

#include "cell.h"

//Structure of a list.
typedef struct s_d_list
{
t_d_cell **heads;
int nbHeads;
} t_d_list; 

#endif