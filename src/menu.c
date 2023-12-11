#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/menu.h"
#include "../includes/datetime.h"
#include "../includes/contact.h"
#include "../includes/appointment.h"
#include "../includes/calendar.h"

void displayMenu()
{
    printf("\033[H\033[J");
    printf("\n+-------------Diary Managment--------------+");
    printf("\n+------------------------------------------+");
    printf("\n+- \033[1;35m Welcome, what would you like to do ? \033[1;0m -+");
    printf("\n[1] Create a Contact");
    printf("\n[2] Create an Appointment");
    printf("\n[3] See all Contacts");
    printf("\n[4] Search for a Contact"); 
    printf("\n[5] Delete Contact");
    printf("\n[6] Delete Appointment");
    printf("\n[7] Save the Appointment File");
    printf("\n[8] Load Appointment File");
    printf("\n[9] Info");
    printf("\n[q] Quit");
    printf("\n+------------------------------------------+");
    printf("\n-> ");
}

void menuQuit()
{
    printf("\033[H\033[J");
    printf("\n+---------------------------------------------------------------+");
    printf("\nYou choose to quit or an error occured, press Enter to continue.");
    printf("\n+---------------------------------------------------------------+");
    fflush(stdin);
    while( getchar() != '\n' );
}

char *scanString(int lenght)
{
    char* buffer = malloc(lenght * sizeof(char));

    fflush(stdin);
    fgets(buffer, lenght, stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing '\n'
    
    return buffer;
}

t_d_calcontact* menuCreateContact()
{
    char verif[2];
    char name[30];
    char surname[30];
    printf("\033[H\033[J");
    printf("\n+-----------------1/3-------------------+");
    printf("\nYou choose to create a contact.");
    printf("\nPlease enter the name of the new contact.");
    printf("\n+---------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");
    scanf("%s",name);

    if (strcmp(name,"quit")==0)
    {
        return NULL;
    }

    printf("\033[H\033[J");
    printf("\n+-------------------------------------2/3---------------------------------------+");
    printf("\nYou entered [\033[1;35m%s\033[1;0m], please enter the surname of the contact now.",name);
    printf("\n+-------------------------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");
    scanf("%s",surname);

    if (strcmp(surname,"quit")==0)
    {
        return NULL;
    }

    printf("\033[H\033[J");
    printf("\n+--------------------------3/3---------------------------------+");
    printf("\nThe operation was a success, contact [%s] [%s] has been created.",name,surname);
    printf("\n+--------------------------------------------------------------+");
    printf("\n[Ready to continue ?]\n-> ");
    fflush(stdin);
    scanf("%s",verif);

    t_d_calcontact* newContact = createCalContact(createInfo(createContact(strdup(name), strdup(surname)))); 
    return newContact;
}

void menuCreateAppointment(t_d_calendar* Calendar)
{
    char verif[20];
    char key[70];
    char yesno[2];
    t_d_date date;     
    t_d_length time;    
    t_d_length length;  
    char purpose[100];


    printf("\033[H\033[J");
    printf("\n+--------------------------------1/8------------------------------------+");
    printf("\nYou choose to create an appointment.");
    printf("\nWhich contact has that appointement ? (enter the key)");
    printf("\n+-----------------------------------------------------------------------+");
    printf("\n[Enter '0' to quit to the main menu.]");
    printf("\n-> ");

    scanf("%s",key);

    if (strcmp(key,"quit")==0)
    {
        return;
    }
    
    // if key is not in calendar, fuck off
    //Dunno how to do that to be honest

    //Maybe here a function to search for the contact if yesno is equal to 1 ?


    printf("\033[H\033[J");
    printf("\n+---------------------------4/8------------------------------------+");
    printf("\nYou entered %s.", key);
    printf("\nPlease enter the date of the appointment in the format [dd mm yyyy].");
    printf("\n+------------------------------------------------------------------+");
    printf("\n[Enter a negative value such as [-1] to quit to the main menu.]");
    printf("\n-> ");

    scanf("%d %d %d",&date.day, &date.month,&date.year);

    if (date.day < 0 && date.month < 0 && date.year < 0)
    {
        return;
    }


    printf("\033[H\033[J");
    printf("\n+---------------------------------------------5/8--------------------------------------------+");
    printf("\nYou entered the date %d/%d/%d, please enter the hour of the appointment in the format [hh:mm].",date.day,date.month,date.year);
    printf("\n+--------------------------------------------------------------------------------------------+");
    printf("\n[Enter a negative value such as [-1] to quit to the main menu.]");
    printf("\n-> ");

    scanf("%d:%d",&time.hours,&time.minutes);

    if ((time.hours < 0 && time.hours > 24) && (time.minutes < 0 && time.minutes > 60))
    {
        return;
    }


    printf("\033[H\033[J");
    printf("\n+--------------------------------------6/8------------------------------------------------+");
    printf("\nYou entered the time %d:%d, please enter the hour of the appointment in the format [xx:xx].",time.hours,time.minutes);
    printf("\n+-----------------------------------------------------------------------------------------+");
    printf("\n[Enter a negative value such as [-1] to go back to the main menu.]");
    printf("\n-> ");

    scanf("%d:%d",&length.hours,&length.minutes);

    if ((length.hours < 0 && length.hours > 24) && (length.minutes < 0 && length.minutes > 60))
    {
        return;
    }

    printf("\033[H\033[J");
    printf("\n+--------------------------------7/8-------------------------------------+");
    printf("\nYou entered the length %d:%d, please enter the purpose of the appointment.",length.hours,length.minutes);
    printf("\nThe format to be used is [xxx_xxxxx_xxxx] in 100 characters");
    printf("\n+------------------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");

    scanf("%s",purpose);


    t_d_appointment* appointment;
    appointment = createAppointment(date, time, length, purpose);
    //addNextAppointment= Should add to the contact except I don't know how to use the key

    printf("\033[H\033[J");
    printf("\n+---------------------------------8/8-----------------------------------+");
    printf("\nThe operation was a sucess, the following appointment has been created :");
    printf("\nDate : %d/%d/%d\nDate Time : %d:%d\nAppointment Length : %d:%d\nPurpose : %s ", date.day, date.month, date.year, time.hours, time.minutes, length.hours, length.minutes, purpose);
    printf("\nIt has been associated to the contact with the key [%d]", key);
    printf("\n+-----------------------------------------------------------------------+");
    printf("\n[Ready to continue ?]\n-> ");
    fflush(stdin);
    scanf("%s", verif);

    return;   //WHERE WE WILL GET THE VALUES
}

void menuSeeAllContacts(t_d_calendar* calendar)
{


    char verif[20];
    printf("\033[H\033[J");
    printf("\n+------------------------------------------------------------------------+");
    printf("\nYou chose to see all the contacts.");
    printf("\nHere is the list of contact, with their associated [key] :\n");
    showCalendar(calendar);
    printf("\n+------------------------------------------------------------------------+");
    printf("\n[Ready to continue ?]");
    printf("\n-> ");

    fflush(stdin);
    scanf("%s", verif);
}

void menuSearchContact()
{
    int menurun=1;
    int i=0;
    char letter;
    char search[30];
    printf("\033[H\033[J");
    printf("\n+-----------------------------------------------+");
    printf("\nYou choose to search for a contact.");
    printf("\nEnter it's name down there one letter at a time :");
    printf("\n+-----------------------------------------------+");
    printf("\n-> ");
    fflush(stdin);
    letter=getchar();
    search[0]=letter;
    while (menurun==1)
    {
        if (letter=='.'){menurun=0;}
        i+=1;
        printf("\033[H\033[J");
        printf("\n+----------------------------------------------------------------+");
        printf("\nEnter the name down there one letter at a time. Write '.' to quit.");
        printf("\nNumber of names found yet [After entering 3 letters]"); 
        //Guess we'll do things here
        printf("\n+----------------------------------------------------------------+");
        printf("\n-> %s ",search);
        fflush(stdin);
        letter=getchar();
        search[i]=letter;
    }
}

void menuDeleteContact()
{
    char verif[10];
    char name[30];
    char surname[30];
    printf("\033[H\033[J");
    printf("\n+------------------1/3-----------------+");
    printf("\nYou choose to delete a contact.");
    printf("\nPlease enter the name of the contact.");
    printf("\n+--------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");
    scanf("%s",name);

    if (strcmp(name,"quit")==0)
    {
        return;
    }

    printf("\033[H\033[J");
    printf("\n+----------------------------2/3-----------------------------+");
    printf("\nYou entered [%s], please enter the surname of the contact now.",name);
    printf("\n+------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");
    scanf("%s",surname);

    if (strcmp(surname,"quit")==0)
    {
        return;
    }

    printf("\033[H\033[J");
    printf("\n+-------------------------------3/4-------------------------------+");
    printf("\nAre you really sure that you want to delete the contact [%s] [%s] ?",name,surname);
    printf("\n+-----------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");

    scanf("%s",verif);

    if (strcmp(verif,"quit")==0)
    {
        return;
    }

    //We need to check if the contact actually exists.
    printf("\033[H\033[J");
    printf("\n+--------------------------4/4-------------------------+");
    printf("\nThe contact [%s] [%s] has been successfuly deleted.",name,surname);
    printf("\n+------------------------------------------------------+");
    printf("\n[Ready to continue ?]\n-> ");
    fflush(stdin);
    scanf("%s",verif);
    return;   //ICI POUR LE RETURN
}

void menuDeleteAppointment()
{
    char verif[10];
    int id;
    char name[30];
    char surname[30];
    printf("\033[H\033[J");
    printf("\n+------------------------1/5----------------------+");
    printf("\nYou choose to delete an appointment.");
    printf("\nPlease enter the name of the contact's appointment.");
    printf("\n+-------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");
    scanf("%s",name);

    if (strcmp(name,"quit")==0)
    {
        return;
    }

    printf("\033[H\033[J");
    printf("\n+-------------------------------------2/5----------------------------------+");
    printf("\nYou entered [%s], please enter the surname of the contact's appointment now.",name);
    printf("\n+--------------------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");
    scanf("%s",surname);

    if (strcmp(surname,"quit")==0)
    {
        return;
    }

    printf("\033[H\033[J");
    printf("\n+-----------------------------------------------3/5-----------------------------------------+");
    printf("\nPlease enter the number ID of the appointment you wish to delete from the contact [%s] [%s] :",name,surname);
    //WE WILL NEED TO SHOW ALL THE APPOINTMENT OF THE CONTACT WITH A NUMBER NEXT TO IT TO IDENTIFY IT
    printf("\n+-------------------------------------------------------------------------------------------+");
    printf("\n[Enter a negative number to quit to the main menu.]");
    printf("\n-> ");

    scanf("%d",&id);

    if (id<0)
    {
        return;
    }

    printf("\033[H\033[J");
    printf("\n+-------------------------------4/5-------------------------------+");
    printf("\nAre you really sure that you want to delete this appointment : ?"); //Here we will show info about that appointment
    printf("\n+-----------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");

    scanf("%s",verif);

    if (strcmp(verif,"quit")==0)
    {
        return;
    }

    //We need to check if the contact actually exists.
    printf("\033[H\033[J");
    printf("\n+--------------------------5/5-------------------------+");
    printf("\nThe apppointment [%d] has been successfuly deleted.",id);
    printf("\n+------------------------------------------------------+");
    printf("\n[Ready to continue ?]\n-> ");
    fflush(stdin);
    scanf("%s",verif);
    return;   //ICI POUR LE RETURN
}

void menuSaveFile()
{
    char answer[2];
    char filename[20];
    char verif[30];
    printf("\033[H\033[J");
    printf("\n+-------------------1/3-------------------+");
    printf("\nYou chose to save your calendar.");
    printf("\nEnter either [y] to save or [n] to go back.");
    printf("\n+-----------------------------------------+");
    printf("\n-> ");
    fflush(stdin);
    scanf("%s",answer);

    if (strcmp(answer,"n")==0)  
    {
        return;
    }
    
    printf("\033[H\033[J");
    printf("\n+-------------------------------2/3------------------------------+");
    printf("\nPlease enter the name of the file which will contain the calendar.");      //PLACEHOLDER HERE
    printf("\nPlease do not put special characters.");
    printf("\n+----------------------------------------------------------------+");
    printf("\n-> ");

    scanf("%s",filename);

    //Probably should make a search for if the file actually already exists.
    printf("\033[H\033[J");
    printf("\n+-------------------------3/3----------------------+");
    printf("\nSuccessfully saved the calendar [%s] in PLACEHOLDER.",filename);           //PLACEHOLDER HERE
    printf("\nEnter anything to continue.");
    printf("\n+--------------------------------------------------+");
    printf("\n-> ");
    scanf("%s", verif);
    //Does the thing
}

void menuLoadFile()
{
    char answer[2];
    char filename[20];
    char verif[30];
    printf("\033[H\033[J");
    printf("\n+-------------------1/3-------------------+");
    printf("\nYou chose to load your calendar.");
    printf("\nEnter either [y] to save or [n] to go back.");
    printf("\n+-----------------------------------------+");
    printf("\n-> ");
    fflush(stdin);
    scanf("%s",answer);

    if (strcmp(answer,"n")==0)  
    {
        return;
    }
    
    printf("\033[H\033[J");
    printf("\n+----------------------2/3------------------------+");
    printf("\nPlease enter the name of the file you wish to load.");      
    printf("\nThe file will be loaded from PLACEHOLDER.");                  //PLACEHOLDER HERE
    printf("\n+-------------------------------------------------+");
    printf("\n-> ");

    scanf("%s",filename);

    //Probably should make search for if the file actually exists.
    printf("\033[H\033[J");
    printf("\n+--------------------------3/3------------------------+");
    printf("\nSuccessfully loaded the calendar [%s] from PLACEHOLDER.",filename);           //PLACEHOLDER HERE
    printf("\nEnter anything to continue.");
    printf("\n+-----------------------------------------------------+");
    printf("\n-> ");
    scanf("%s", verif);
    //Does the thing   
}

void menuInfo()
{
    int run = 1;
    char choice;
    char verif[2];
    while (run == 1)
    {
        printf("\033[H\033[J");
        printf("\n+-------------------------------------+");
        printf("\n+- What do you wish to learn about ? -+");
        printf("\n[1] Credits");
        printf("\n[2] Calculation Time");
        printf("\n[3] Quit the Info Menu");
        printf("\n+-------------------------------------+");
        printf("\n-> ");
        fflush(stdin);
        scanf("%c", &choice);
        fflush(stdin);
        switch (choice)
        {
            case '1':
                printf("\033[H\033[J");
                printf("\n+-----------------------------------------------------------+");
                printf("\nMade for an Efrei Project by :");           
                printf("\n-> Antoine IGLESIAS-TALLON (Still MIA)");
                printf("\n-> Antoine MEUNIER (No link to the school principal)");
                printf("\n-> Nassim AININE (Not an Antoine)");
                printf("\n+-----------------------------------------------------------+");
                printf("\n-> ");
                fflush(stdin);
                scanf("%s", verif);
                break;
            case '2':
                printf("\033[H\033[J");
                printf("\n+---------------------------------------------------+");
                printf("\nYeah calculations, yeahhhh");
                printf("\n+---------------------------------------------------+");
                printf("\n-> ");
                fflush(stdin);
                scanf("%s", verif);
                break;
            case '3':
                run=0;
                break;
        }
    }
}


