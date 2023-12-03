#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../includes/timer.h"
#include "../includes/list.h"
#include "../includes/cell.h"

#define MAX_ITER 100000

void part1()
{
    t_d_list basicList = createEmptyList(5);

    displayAllLevels(basicList);
    displayAlign(basicList);

    printf("=====\n");

    insertCellAtHead(&basicList, 7, 2);
    insertCellAtHead(&basicList, 4, 3);
    insertCellAtHead(&basicList, 3, 4);

    displayAlign(basicList);

    printf("\n");

    insertInOrder(&basicList, 1, 1);
    insertInOrder(&basicList, 99, 5);
    insertInOrder(&basicList, 5, 2);

    displayAlign(basicList);

    printf("=====\n");

    t_d_list listExample;
    listExample = createExampleList(3);

    displayAlign(listExample);
}

void part2()
{
    int initialLevel = 1;
    int finalLevel = 17;
    
    t_d_list list;

    char *time_classic;
    char *time_high;
    int level, maxNum;

    for (level = initialLevel; level < finalLevel; level++)
    {
        list = createExampleList(level);
        maxNum = pow(2, level);

        // Classic search
        startTimer();
        for (size_t i = 0; i < MAX_ITER; i++)
        {
            searchClassic(list, rand()%maxNum);
        }
        stopTimer();
        time_classic = getTimeAsString();
        
        // High search
        startTimer();
        for (size_t i = 0; i < MAX_ITER; i++)
        {
            searchHigh(list, rand()%maxNum);
        }
        stopTimer();
        time_high = getTimeAsString();
        
        // Save to file
        fprintf(stdout, "%d\t%s\t%s\n", level, time_classic, time_high);
    }
}

int oral_main()
{
    part2();
    return 0;
}