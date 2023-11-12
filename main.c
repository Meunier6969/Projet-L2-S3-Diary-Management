#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include<windows.h>

#include "list.h"
#include "timer/timer.h"

#define MAX_ITER 1000000

int main()
{
    int run=1;
    while (run=1){
        printf("\n+-------------Diary Managment--------------+");
        printf("\n+------------------------------------------+");
        printf("\n+-  Welcome, what would you like to do ?  -+");
        printf("\n[1] Create a Contact\n[2] Create an Appointment\n[3] Delete an Appointment\n[4] View Contact Appointment");
        printf("\n[5] Search for a Contact\n[6] Save the Appointment File\n[7] Load Appointment File\n[8] Info\n[9] Quit\n");
        printf("Enter a number : ");
        char choice;
        choice=getchar();
        switch(choice){
        case '1':
            printf("\nPlease specify the name of the contact. Write 'quit' to leave.");
            printf("\nEnter a name or 'quit' : ");
            char name[30];
            scanf("%s",name);
            if (strcmp(name,"quit")!=0) //Check if the name is correct. 
            {
                printf("You choose [%s], now please indicate the surname. Enter 'quit' to leave.",name);
                printf("\nEnter a surname or 'quit' : ");
                char surname[30];
                scanf("%s",surname);
                if (strcmp(surname,"quit")!=0) //Check if the surname is correct
                {
                    printf("The contact [%s] [%s] has been successfully created", name, surname);
                    break;
                }
                else
                {
                    printf("You wrote 'quit', you will now go back");
                    break;
                }
                }
            else
            {
                printf("You wrote 'quit', you will now go back");
                break;
            }
        case '9':
            exit(0);
        }
    }
}












/*
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
*/