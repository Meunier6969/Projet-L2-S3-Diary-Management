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
    char verif[20];
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

void menuCreateAppointment() //Date xx/xx/xxxx -> Heure xx:xx -> Length xx:xx
{
    int run=1;
    char verif[20];
    char name[20]; char surname[20];
    int day; int month; int year;   //Variables for the date.
    int dhour; int dmin;            //Variables for the appointment starting time.
    int lhour; int lmin;            //Variables for the length of the appointment.
    char purpose[100];
    while (run==1)
    {
        printf("\033[H\033[J");
        printf("\n+------------------------------------------------------------------+");
        printf("\nYou choose to create an appointment.");
        printf("\nPlease enter the name of the contact's appointment in the format [name_surname].");
        printf("\n+------------------------------------------------------------------+");
        printf("\n[Enter 'quit' to quit to the main menu.]");
        printf("\n-> ");
        scanf("%s_%s", name,surname); //WILL NEED A SPECIAL FUNCTION CAUSE I DONT WANT TO ADD ANOTHER FRIKING IF
        if (strcmp(name,"quit")!=0 && strcmp(surname,"quit")!=0) //WILL ALSO NEED TO CHECK IF CONTACT EXISTS
        {
            printf("\033[H\033[J");
            printf("\n+------------------------------------------------------------------+");
            printf("\nYou entered the name %s and the surname %s.", name, surname);
            printf("\nPlease enter the date of the appointment in the format [xx/xx/xxxx].");
            printf("\n+------------------------------------------------------------------+");
            printf("\n[Enter a negative value such as [-1] to quit to the main menu.]");
            printf("\n-> ");
            scanf("%d/%d/%d",&day,&month,&year);
            if (day >= 0 && month >=0 && year >=1000)
            {
                printf("\033[H\033[J");
                printf("\n+--------------------------------------------------------------------------------------------+");
                printf("\nYou entered the date %d/%d/%d, please enter the hour of the appointment in the format [xx:xx].",day,month,year);
                printf("\n+--------------------------------------------------------------------------------------------+");
                printf("\n[Enter a negative value such as [-1] to go back to the very start.]");
                printf("\n-> ");
                scanf("%d:%d",&dhour,&dmin);
                if ((dhour >=0 && dhour <24) && (dmin >= 0 && dmin < 60))
                {
                    printf("\033[H\033[J");
                    printf("\n+--------------------------------------------------------------------------------------------+");
                    printf("\nYou entered the time %d:%d, please enter the hour of the appointment in the format [xx:xx].",dhour,dmin);
                    printf("\n+--------------------------------------------------------------------------------------------+");
                    printf("\n[Enter a negative value such as [-1] to go back to the very start.]");
                    printf("\n-> ");
                    scanf("%d:%d",&lhour,&lmin);
                    if ((lhour >=0 && lhour <24) && (lmin >= 0 && lmin < 60))
                    {
                        printf("\033[H\033[J");
                        printf("\n+--------------------------------------------------------------------------------------------+");
                        printf("\nYou entered the length %d:%d, please enter the purpose of the appointment.",lhour,lmin);
                        printf("\nThe format to be used is [xxx_xxxxx_xxxx] in 100 characters (Need fixin')");
                        printf("\n+--------------------------------------------------------------------------------------------+");
                        printf("\n[Enter 'quit' to quit to the very start.]");
                        printf("\n-> ");
                        scanf("%s",purpose);
                        printf("\033[H\033[J");
                        printf("\n+---------------------------------------------------------------------------------------+");
                        printf("\nThe operation was a sucess, the following appointment has been created :");
                        printf("\nDate : %d/%d/%d\nDate Time : %d:%d\nAppointment Length : %d:%d\nPurpose : %s ", day, month, year, dhour, dmin, lhour, lmin, purpose);
                        printf("\n+---------------------------------------------------------------------------------------+");
                        printf("\n[Ready to continue ? You cannot go back anyway.]\n-> ");
                        scanf("%s", &verif);
                        run=0;
                        //WHERE WE WILL GET THE VALUES
                    }
                    else if (strcmp(purpose,"quit")==0)
                    {
                        printf("\033[H\033[J");
                        printf("\n+---------------------------------------------------------------+");
                        printf("\nYou choose to quit, you will now go back to the first screen.");
                        printf("\n+---------------------------------------------------------------+");
                    }
                }
                else
                {
                    printf("\033[H\033[J");
                    printf("\n+---------------------------------------------------------------+");
                    printf("\nYou choose to quit, you will now go back to the first screen.");
                    printf("\n+---------------------------------------------------------------+");
                }
            }
            else
            {
                printf("\033[H\033[J");
                printf("\n+-----------------------------------------------------------+");
                printf("\nYou choose to quit, you will now go back to the first screen.");
                printf("\n+-----------------------------------------------------------+");
            }
        }
        else if (strcmp(name,"quit")==0)
        {
             printf("\033[H\033[J");
            printf("\n+------------------------+");
            printf("\nYou choose to quit. Byebye.");
            printf("\n+------------------------+");
            run=0;
        }
    }
}

void menuDeleteAppointment()
{
    printf("no");
}