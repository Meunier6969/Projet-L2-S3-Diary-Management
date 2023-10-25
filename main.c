#include <stdio.h>

#include "list.h"

int main()
{
    t_d_cell* cell = createCell(69, 5);
    
    cell->next[0] = (void*) 0x69696969;
    displayCell(*cell);
    
    return 0;
}