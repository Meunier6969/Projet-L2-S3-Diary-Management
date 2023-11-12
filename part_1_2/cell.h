#ifndef _INCLUDE_CELL
#define _INCLUDE_CELL

// Part 1 & 2
// Structure of a cell.
typedef struct s_d_cell
{
    int value;
    int nbLevels;
    struct s_d_cell **next;
} t_d_cell; 

t_d_cell* createCell(int value, int height);
void displayCell(t_d_cell cell);

#endif