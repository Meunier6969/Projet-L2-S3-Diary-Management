#include <stdio.h>

#include "list.h"

int main()
{
    t_d_list list = createEmptyList(5);

    displayAllLevels(list);
    
    return 0;
}