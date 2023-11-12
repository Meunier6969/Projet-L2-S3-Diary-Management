#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "list.h"
#include "timer/timer.h"

#define MAX_ITER 1000000

int main()
{
    int initialLevel = 1;
    int finalLevel = 17;
    
    t_d_list list;

    FILE *log_file = fopen("log.txt", "w");
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
        fprintf(log_file, "%d\t%s\t%s\n", level, time_classic, time_high);
        fprintf(stdout, "%d\t%s\t%s\n", level, time_classic, time_high);
    }

    fclose(log_file);
    return 0;
}
