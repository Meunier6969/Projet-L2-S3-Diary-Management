#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/menu.h"



void displayMenu()
{
    printf("\033[H\033[J");
    printf("\n+-------------Diary Managment--------------+");
    printf("\n+------------------------------------------+");
    printf("\n+-  Welcome, what would you like to do ?  -+");
    printf("\n[1] Create a Contact");
    printf("\n[2] Create an Appointment");
    printf("\n[3] Delete an Appointment");
    printf("\n[4] View Contact Appointment");
    printf("\n[5] Search for a Contact");
    printf("\n[6] Save the Appointment File");
    printf("\n[7] Load Appointment File");
    printf("\n[8] Info");
    printf("\n[9] Quit");
    printf("\n+------------------------------------------+");
    printf("\n-> ");
}

char *scanString()
{
    return malloc(0);
}

void menuCreateContact()
{
    int run=1;
    char verif;
    char name[30];
    char surname[30];
    while (run==1)
    {
        printf("\033[H\033[J");
        printf("\n+---------------------------------------+");
        printf("\nYou choose to create a contact.");
        printf("\nPlease enter the name of the new contact.");
        printf("\n+---------------------------------------+");
        printf("\n[Enter 'quit' to quit to the main menu.]");
        printf("\n-> ");
        scanf("%s",name); //FAUDRA REMPLACER PAR SCAN
        if (strcmp(name,"quit")!=0)
        {
            printf("\033[H\033[J");
            printf("\n+------------------------------------------------------------+");
            printf("\nYou entered [%s], please enter the surname of the contact now.",name);
            printf("\n+------------------------------------------------------------+");
            printf("\n[Enter 'quit' to quit to the previous menu.]");
            printf("\n-> ");
            scanf("%s",surname); //FAUDRA REMPLACER PAR SCAN
            if (strcmp(surname,"quit")!=0)
            {
                printf("\033[H\033[J");
                printf("\n+-----------------------------------------------------------------+");
                printf("\nThe operation was a sucess, contact [%s] [%s] has been created.",name,surname);
                printf("\n+-----------------------------------------------------------------+");
                printf("\n[Ready to continue ? You cannot go back anyway.]\n-> ");
                scanf("%s", &verif);
                //FAUDRA METTRE LA RECUPERATION DE NOM ET SURNOM ICI OU DIRECT LA FONCTION DE CREATION ?
            }
            else if (strcmp(surname,"quit")==0)
            {
                printf("\033[H\033[J");
                printf("\n+---------------------------------------------------------------+");
                printf("\nYou choose to quit, you will now go back to the precedent screen.");
                printf("\n+---------------------------------------------------------------+");
            }
        }
        else if (strcmp(name,"quit")==0)
        {
            printf("\033[H\033[J");
            printf("\n+------------------------+");
            printf("\nYou choose to quit. Bybye.");
            printf("\n+------------------------+");
            run=0;
        }
    }
}