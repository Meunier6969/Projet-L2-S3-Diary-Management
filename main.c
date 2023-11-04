#include <stdio.h>

#include "list.h"

int main()
{
    t_d_list list = createExampleList(3);

    displayAlign(list);
    
    printf("0: %p\n", searchClassic(list, 0));
    printf("1: %p\n", searchClassic(list, 1));
    printf("4: %p\n", searchClassic(list, 4));
    printf("7: %p\n", searchClassic(list, 7));
    printf("9: %p\n", searchClassic(list, 9));

    return 0;
}
