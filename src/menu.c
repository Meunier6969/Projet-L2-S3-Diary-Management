#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/menu.h"
#include "../includes/datetime.h"
#include "../includes/contact.h"
#include "../includes/appointment.h"

void displayMenu()
{
    printf("\033[H\033[J");
    printf("\n+-------------Diary Managment--------------+");
    printf("\n+------------------------------------------+");
    printf("\n+-  Welcome, what would you like to do ?  -+");
    printf("\n[1] Create a Contact");
    printf("\n[2] Create an Appointment");
    printf("\n[3] Search for a Contact"); //Will be used to search for a contact, see it's appointment, but also delete them, easier than so many function
    printf("\n[4] Save the Appointment File");
    printf("\n[5] Load Appointment File");
    printf("\n[6] Info");
    printf("\n[7] Quit");
    printf("\n+------------------------------------------+");
    printf("\n-> ");
}

void menuQuit()
{
    printf("\033[H\033[J");
    printf("\n+---------------------------------------------------------------+");
    printf("\nYou choose to quit, press Enter to continue.");
    printf("\n+---------------------------------------------------------------+");
    fflush(stdin);
    while( getchar() != '\n' );
}

char *scanString(int lenght)
{
    char* buffer = malloc(lenght * sizeof(char));

    fgets(buffer, lenght, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing '\n'
    
    return buffer;
}

void menuCreateContact()
{
    int menurun=1;
    char verif[30];
    char name[30];
    char surname[30];
    while (menurun==1)
    {
        printf("\033[H\033[J");
        printf("\n+---------------------------------------+");
        printf("\nYou choose to create a contact.");
        printf("\nPlease enter the name of the new contact.");
        printf("\n+---------------------------------------+");
        printf("\n[Enter 'quit' to quit to the main menu.]");
        printf("\n-> ");
        scanf("%s",name);
        if (strcmp(name,"quit")!=0)
        {
            printf("\033[H\033[J");
            printf("\n+------------------------------------------------------------+");
            printf("\nYou entered [%s], please enter the surname of the contact now.",name);
            printf("\n+------------------------------------------------------------+");
            printf("\n[Enter 'quit' to quit to the previous menu.]");
            printf("\n-> ");
            scanf("%s",surname);
            if (strcmp(surname,"quit")!=0)
            {
                printf("\033[H\033[J");
                printf("\n+-----------------------------------------------------------------+");
                printf("\nThe operation was a sucess, contact [%s] [%s] has been created.",name,surname);
                printf("\n+-----------------------------------------------------------------+");
                printf("\n[Ready to continue ? You cannot go back anyway.]\n-> ");
                fflush(stdin);
                while( getchar() != '\n' );
                menurun=0;
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
            menurun=0;
        }
    }
}

/*
void newCA()
{
    void* bing = NULL;
    t_d_date date;
    t_d_length length, time;
    char* purpose;

    printf("create appointement");
    printf("entre name and surname");
    scanf("%s %s", bing ,bing);

    printf("enter date [dd mm yyyy]");
    while (date.day >= 0 && date.month >=0 && date.year >=1000)
    {
        printf("> ");
        fflush(stdin);
        scanf("%d %d %d", date.day, date.month, date.year);
    }

    if (date.day == -1) return NULL;

    printf("enter time [hh mm]");
    while ((length.hours >=0 && length.hours <24) && (length.minutes >= 0 && length.minutes < 60))
    {
        printf("> ");
        fflush(stdin);
        scanf("%d %d", length.hours, length.minutes);
    }

    t_d_appointment* newAppointment = createAppointment(date, time, length, purpose);
}
*/

void menuCreateAppointment() //Date xx/xx/xxxx -> Heure xx:xx -> Length xx:xx
{
    int run=1;
    char verif[20];
    char name[20]; char surname[20];
    t_d_date date;   //Variables for the date.
    t_d_length time;            //Variables for the appointment starting time.
    t_d_length length;            //Variables for the length of the appointment.
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
        scanf("%s_%s", name, surname); //WILL NEED A SPECIAL FUNCTION CAUSE I DONT WANT TO ADD ANOTHER FRIKING IF
        if (strcmp(name,"quit")!=0 && strcmp(surname,"quit")!=0) //WILL ALSO NEED TO CHECK IF CONTACT EXISTS
        {
            printf("\033[H\033[J");
            printf("\n+------------------------------------------------------------------+");
            printf("\nYou entered the name %s and the surname %s.", name, surname);
            printf("\nPlease enter the date of the appointment in the format [dd mm yyyy].");
            printf("\n+------------------------------------------------------------------+");
            printf("\n[Enter a negative value such as [-1] to quit to the main menu.]");
            printf("\n-> ");
            scanf("%d %d %d",&date.day,&date.month,&date.year);

            if (date.day >= 0 && date.month >=0 && date.year >=1000)
            {
                printf("\033[H\033[J");
                printf("\n+--------------------------------------------------------------------------------------------+");
                printf("\nYou entered the date %d/%d/%d, please enter the hour of the appointment in the format [hh:mm].",date.day,date.month,date.year);
                printf("\n+--------------------------------------------------------------------------------------------+");
                printf("\n[Enter a negative value such as [-1] to go back to the very start.]");
                printf("\n-> ");
                scanf("%d:%d",&time.hours,&time.minutes);
                if ((time.hours >=0 && time.hours <24) && (time.minutes >= 0 && time.minutes < 60))
                {
                    printf("\033[H\033[J");
                    printf("\n+--------------------------------------------------------------------------------------------+");
                    printf("\nYou entered the time %d:%d, please enter the hour of the appointment in the format [xx:xx].",time.hours,time.minutes);
                    printf("\n+--------------------------------------------------------------------------------------------+");
                    printf("\n[Enter a negative value such as [-1] to go back to the very start.]");
                    printf("\n-> ");
                    scanf("%d:%d",&length.hours,&length.minutes);
                    if ((length.hours >=0 && length.hours <24) && (length.minutes >= 0 && length.minutes < 60))
                    {
                        printf("\033[H\033[J");
                        printf("\n+--------------------------------------------------------------------------------------------+");
                        printf("\nYou entered the length %d:%d, please enter the purpose of the appointment.",length.hours,length.minutes);
                        printf("\nThe format to be used is [xxx_xxxxx_xxxx] in 100 characters (Need fixin')");
                        printf("\n+--------------------------------------------------------------------------------------------+");
                        printf("\n[Enter 'quit' to quit to the very start.]");
                        printf("\n-> ");
                        scanf("%s",purpose);
                        printf("\033[H\033[J");
                        printf("\n+---------------------------------------------------------------------------------------+");
                        printf("\nThe operation was a sucess, the following appointment has been created :");
                        printf("\nDate : %d/%d/%d\nDate Time : %d:%d\nAppointment Length : %d:%d\nPurpose : %s ", date.day, date.month, date.year, time.hours, time.minutes, length.hours, length.minutes, purpose);
                        printf("\n+---------------------------------------------------------------------------------------+");
                        printf("\n[Ready to continue ? You cannot go back anyway.]\n-> ");
                        fflush(stdin);
                        while( getchar() != '\n' );
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


void menuSearchContact()
{
    int menurun=1;
    int i=0;
    char letter;
    char search[30];
    printf("\033[H\033[J");
    printf("\n+------------------------------------------------+");
    printf("\nYou choose to search for a contact.");
    printf("\nEnter it's name down there one letter at a time :");
    printf("\n+------------------------------------------------+");
    printf("\n-> ");
    fflush(stdin);
    letter=getchar();
    search[0]=letter;
    while (menurun==1)
    {
        if (letter=='.'){menurun=0;}
        i+=1;
        printf("\033[H\033[J");
        printf("\n+-----------------------------------------------------------------+");
        printf("\nEnter the name down there one letter at a time. Write '.' to quit.");
        printf("\nNumber of names found yet [After entering 3 letters]"); 
        //Guess we'll do things here
        printf("\n+-----------------------------------------------------------------+");
        printf("\n-> %s ",search);
        fflush(stdin);
        letter=getchar();
        search[i]=letter;
    }
}

void menuSaveFile()
{
    int menurun=1;
    char answer;
    char verif[30];
    while (menurun==1)
    {
        printf("\033[H\033[J");
        printf("\n+-------------------------------------------+");
        printf("\nYou choose to save your calendar.");
        printf("\nEnter either [y] to save or [n] to go back.");
        printf("\n+-------------------------------------------+");
        printf("\n-> ");
        fflush(stdin);
        while ((answer = getchar()) == '\n');
        if (answer == 'y')
        {
            printf("\033[H\033[J");
            printf("\n+---------------------------------------------+");
            printf("\nSuccessfully saved the calendar in PLACEHOLDER.");           //PLACEHOLDER HERE
            printf("\nEnter anything to continue.");
            printf("\n+---------------------------------------------+");
            printf("\n-> ");
            scanf("%s", verif);
            //Does the thing
        }
        else if (answer == 'n')
        {
            menurun=0;
        }
    }
}

void menuLoadFile()
{
    int menurun=1;
    char answer;
    char verif[30];
    while (menurun==1)
    {
        printf("\033[H\033[J");
        printf("\n+-----------------------------------------------+");
        printf("\nYou choose to load the calendar from PLACEHOLDER.");
        printf("\nEnter either [y] to load or [n] to go back.");
        printf("\n+-----------------------------------------------+");
        printf("\n-> ");
        fflush(stdin);
        while ((answer = getchar()) == '\n');
        if (answer == 'y')
        {
            printf("\033[H\033[J");
            printf("\n+-------------------------------+");
            printf("\nSuccessfully loaded the calendar.");           //PLACEHOLDER HERE
            printf("\nEnter anything to continue.");
            printf("\n+-------------------------------+");
            printf("\n-> ");
            scanf("%s", verif);
            //Does the thing
            menurun=0;
        }
        else if (answer == 'n')
        {
            menurun=0;
        }
    }
}

void menuInfo()
{
    int run = 1;
    char choice;
    char verif[30];
    while (run == 1)
    {
        printf("\033[H\033[J");
        printf("\n+----------------------------------------------------+");
        printf("\n+- What do you wish to learn about ? -+");
        printf("\n[1] Credits");
        printf("\n[2] Calculation Time");
        printf("\n[3] Quit the Info Menu");
        printf("\n+---------------------------------------------------+");
        printf("\n-> ");
        fflush(stdin);
        scanf("%c", &choice);
        switch (choice)
        {
            case '1':
                printf("\033[H\033[J");
                printf("\n+------------------------------------------------------------+");
                printf("\nMade for an Efrei Project by :");           
                printf("\n-> Antoine IGLESIAS-TALLON (Still MIA)");
                printf("\n-> Antoine MEUNIER (No link to the school principal (yet...))");
                printf("\n-> Nassim AININE (Not an Antoine)");
                printf("\n+------------------------------------------------------------+");
                printf("\n-> ");
                fflush(stdin);
                while( getchar() != '\n' );
                break;
            case '2':
                printf("\033[H\033[J");
                printf("\n+--------------------------------------------------+");
                printf("\nYeah calculations, yeahhhh");
                printf("\n+---------------------------------------------------+");
                printf("\n-> ");
                fflush(stdin);
                while( getchar() != '\n' );
                break;
            case '3':
                run=0;
                break;
        }
    }
}


