#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    printf("\n[\033[1;35m1\033[1;0m] Create a Contact");
    printf("\n[\033[1;35m2\033[1;0m] Create an Appointment");
    printf("\n[\033[1;35m3\033[1;0m] See all Contacts");
    printf("\n[\033[1;35m4\033[1;0m] Search for a Contact"); 
    printf("\n[\033[1;35m5\033[1;0m] Delete Contact");
    printf("\n[\033[1;35m6\033[1;0m] Delete Appointment");
    printf("\n[\033[1;35m7\033[1;0m] Save the Appointment File");
    printf("\n[\033[1;35m8\033[1;0m] Load Appointment File");
    printf("\n[\033[1;35m9\033[1;0m] Info");
    printf("\n[\033[1;35mq\033[1;0m] Quit");
    printf("\n+------------------------------------------+");
    printf("\n-> ");
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
    printf("\nThe operation was a success, contact [\033[1;35m%s\033[1;0m] [\033[1;35m%s\033[1;0m] has been created.",name,surname);
    printf("\n+--------------------------------------------------------------+");
    printf("\n[Ready to continue ?]\n-> ");
    fflush(stdin);
    scanf("%s",verif);

    t_d_calcontact* newContact = createCalContact(createInfo(createContact(strdup(name), strdup(surname)))); 
    return newContact;
}

t_d_appointment* menuCreateAppointment(t_d_calendar* calendar)
{
    char verif[20];
    char search[70];
    t_d_date date;     
    t_d_length time;    
    t_d_length length;  
    char purpose[100];

    printf("\033[H\033[J");
    printf("\n+--------------------------------1/6------------------------------------+");
    printf("\nYou choose to create an appointment.");
    printf("\nWhich contact has that appointement ? [name_surname]");
    printf("\n+-----------------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");

    fflush(stdin);
    scanf("%70s", search);

    if (strcmp(search,"quit")==0)
    {
        return NULL;
    }

    t_d_calcontact* contact = searchCalContact(calendar, search);

    if (contact == NULL)
    {
        printf("\033[H\033[J");
        printf("\n+----------------------2/2-----------------------+");
        printf("\nNo informations has been found about that contact.");
        printf("\n+------------------------------------------------+");
        printf("\n[Ready to continue ?]");
        printf("\n-> ");

        fflush(stdin);
        scanf("%s", verif);
        return NULL;
    }


    printf("\033[H\033[J");
    printf("\n+---------------------------2/6------------------------------------+");
    printf("\nYou entered \033[1;35m%s\033[1;0m.", search);
    printf("\nPlease enter the date of the appointment in the format [dd mm yyyy].");
    printf("\n+------------------------------------------------------------------+");
    printf("\n[Enter a negative value such as [-1] to quit to the main menu.]");
    printf("\n-> ");

    scanf("%d %d %d",&date.day, &date.month,&date.year);

    if (date.day < 0 || date.month < 0 || date.year < 0)
    {
        return NULL;
    }


    printf("\033[H\033[J");
    printf("\n+---------------------------------------------3/6--------------------------------------------+");
    printf("\nYou entered the date \033[1;35m%d/%d/%d\033[1;0m, please enter the hour of the appointment in the format [hh:mm].",date.day,date.month,date.year);
    printf("\n+--------------------------------------------------------------------------------------------+");
    printf("\n[Enter a negative value such as [-1] to quit to the main menu.]");
    printf("\n-> ");

    scanf("%d:%d",&time.hours,&time.minutes);

    if ((time.hours < 0 || time.hours > 24) || (time.minutes < 0 || time.minutes > 60))
    {
        return NULL;
    }


    printf("\033[H\033[J");
    printf("\n+--------------------------------------4/6------------------------------------------------+");
    printf("\nYou entered the time \033[1;35m%d:%d\033[1;0m, please enter the hour of the appointment in the format [xx:xx].",time.hours,time.minutes);
    printf("\n+-----------------------------------------------------------------------------------------+");
    printf("\n[Enter a negative value such as [-1] to go back to the main menu.]");
    printf("\n-> ");

    scanf("%d:%d",&length.hours,&length.minutes);

    if ((length.hours < 0 || length.hours > 24) || (length.minutes < 0 || length.minutes > 60))
    {
        return NULL;
    }

    printf("\033[H\033[J");
    printf("\n+--------------------------------5/6-------------------------------------+");
    printf("\nYou entered the length \033[1;35m%d:%d\033[1;0m, please enter the purpose of the appointment.",length.hours,length.minutes);
    printf("\nThe format to be used is [xxx_xxxxx_xxxx] in 100 characters");
    printf("\n+------------------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");

    scanf("%s",purpose);

    t_d_appointment* appointment;
    appointment = createAppointment(date, time, length, strdup(purpose));
    addAppointement(contact->contact, appointment);

    printf("\033[H\033[J");
    printf("\n+---------------------------------6/6-----------------------------------+");
    printf("\nThe operation was a sucess, the following appointment has been created :");
    printf("\n\n\033[1;35mDate\033[1;0m : %d/%d/%d\n\033[1;35mDate Time\033[1;0m : %d:%d\n\033[1;35mAppointment Length\033[1;0m : %d:%d\n\033[1;35mPurpose\033[1;0m : %s ", date.day, date.month, date.year, time.hours, time.minutes, length.hours, length.minutes, purpose);
    printf("\n\nIt has been associated to the contact with the key [%s]", search);
    printf("\n+-----------------------------------------------------------------------+");
    printf("\n[Ready to continue ?]\n-> ");
    fflush(stdin);
    scanf("%s", verif);

    return appointment;
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

t_d_calcontact* menuSearchContact(t_d_calendar* calendar)
{
    char verif[2];
    char search[30];
    printf("\033[H\033[J");
    printf("\n+-------------------------1/2---------------------------+");
    printf("\nYou chose to search for a contact.");
    printf("\nPlease enter it's key in the format [surname_firstname] :");
    printf("\n+-------------------------------------------------------+");
    printf("\n-> ");

    fflush(stdin);
    scanf("%30s", search);

    t_d_calcontact* contact = searchCalContact(calendar, search);

    if (contact != NULL)
    {
        printf("\033[H\033[J");
        printf("\n+----------------------2/2------------------------+");
        printf("\nHere are the informations found about the contact :\n");
        displayInfo(contact->contact);
        printf("+-------------------------------------------------+");
        printf("\n[Ready to continue ?]");
        printf("\n-> ");

        fflush(stdin);
        scanf("%s", verif);
    }
    else
    {
        printf("\033[H\033[J");
        printf("\n+----------------------2/2-----------------------+");
        printf("\nNo informations has been found about that contact.");
        printf("\n+------------------------------------------------+");
        printf("\n[Ready to continue ?]");
        printf("\n-> ");

        fflush(stdin);
        scanf("%s", verif);
    }
    return contact;
    
}

void menuDeleteContact(t_d_calendar **Calendar)
{
    char verif[10];
    char search[30];
    printf("\033[H\033[J");
    printf("\n+--------------------------------1/3-----------------------------+");
    printf("\nYou choose to delete a contact.");
    printf("\nPlease enter the name of the contact in the format [name_surname].");
    printf("\n+----------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");
    scanf("%s",search);


    t_d_calcontact* contact = searchCalContact(*Calendar, search);

    if (contact != NULL)
    {
        printf("\033[H\033[J");
        printf("\n+-------------------------------2/3-------------------------------+");
        printf("\nAre you really sure that you want to delete the contact [\033[1;35m%s\033[1;0m] ?", search);
        printf("\n+-----------------------------------------------------------------+");
        printf("\n[Enter 'quit' to quit to the main menu.]");
        printf("\n-> ");

        scanf("%s",verif);

        if (strcmp(verif,"quit")==0)
        {
            return;
        }

        deleteCalContact(Calendar,contact);

        printf("\033[H\033[J");
        printf("\n+--------------------------3/3-------------------------+");
        printf("\nThe contact [\033[1;35m%s\033[1;0m] has been successfuly deleted.", search);
        printf("\n+------------------------------------------------------+");
        printf("\n[Ready to continue ?]\n-> ");
        fflush(stdin);
        scanf("%s",verif);
        return;
    }
    else
    {
        printf("\033[H\033[J");
        printf("\n+----------------------2/2-----------------------+");
        printf("\nNo informations has been found about that contact.");
        printf("\n+------------------------------------------------+");
        printf("\n[Ready to continue ?]");
        printf("\n-> ");

        fflush(stdin);
        scanf("%s", verif);
    }
}

void menuDeleteAppointment(t_d_calendar *calendar)
{
    char verif[10];
    char key[30];
    int id;

    printf("\033[H\033[J");
    printf("\n+------------------------1/5----------------------+");
    printf("\nYou choose to delete an appointment.");
    printf("\nPlease enter the key of the contact's appointment. (firstname_surname)");
    printf("\n+-------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");
    
    fflush(stdin);
    scanf("%30s",key);

    if (strcmp(key,"quit")==0)
    {
        return;
    }

    t_d_calcontact* contact = searchCalContact(calendar, key);

    if (contact == NULL)
    {
        printf("\033[H\033[J");
        printf("\n+------------------------------------------------+");
        printf("\nNo informations has been found about that contact.");
        printf("\n+------------------------------------------------+");
        printf("\n[Ready to continue ?]");
        printf("\n-> ");

        fflush(stdin);
        scanf(" ");
        return;
    }

    printf("\033[H\033[J");
    printf("\n+-----------------------------------------------3/5-----------------------------------------+");
    printf("\nPlease enter the number ID of the appointment you wish to delete from the contact [%s] :\n",key);
    displayInfo(contact->contact);
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
    printf("\nAre you really sure that you want to delete this appointment : ?");
    printf("\n+-----------------------------------------------------------------+");
    printf("\n[Enter 'quit' to quit to the main menu.]");
    printf("\n-> ");

    scanf("%s",verif);

    if (strcmp(verif,"quit")==0)
    {
        return;
    }

    deleteAppointment(&(contact->contact->firstAppointment), id);

    printf("\033[H\033[J");
    printf("\n+--------------------------5/5-------------------------+");
    printf("\nThe apppointment [\033[1;35m%d\033[1;0m] has been successfuly deleted.",id);
    printf("\n+------------------------------------------------------+");
    printf("\n[Ready to continue ?]\n-> ");
    fflush(stdin);
    scanf("%s",verif);
}

void menuSaveFile(t_d_calendar* calendar)
{
    char answer[2];
    char filename[40];
    char verif[30];
    printf("\033[H\033[J");
    printf("\n+-------------------1/3-------------------+");
    printf("\nYou chose to save your calendar.");
    printf("\nEnter either [\033[1;35my\033[1;0m] to save or [\033[1;35mn\033[1;0m] to go back.");
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
    printf("\nPlease enter the name of the file which will contain the calendar.");
    printf("\nPlease do not put special characters.");
    printf("\n+----------------------------------------------------------------+");
    printf("\n-> ");

    scanf("%40s",filename);

    FILE *save;
    // check if file exists
    if ((save = fopen(filename, "r")))
    {
        fclose(save);
        // if yes, ask if overwrite
        printf("File already exist. Do you want to overwrite it ? (\033[1;35my/n\033[1;0m)\n");
        printf("-> ");

        fflush(stdin);
        scanf("%s",answer);

        // if not, go back
        if (strcmp(answer,"n")==0)  
            return;
    }
    // reopen the file to overwrite its content
    save = fopen(filename, "w");

    // for each contact in calendar
    char name[70] = "";
    t_d_calcontact* crawler = calendar->head;
    while (crawler != NULL)
    {
        strcpy(name, "");
        // make the name
        strcat(name, crawler->contact->contact->surname);
        strcat(name, " ");
        strcat(name, crawler->contact->contact->firstName);
        strcat(name, "\n");
        // uppercase it
        for(int i = 0; name[i]; i++)
            name[i] = toupper(name[i]);

        // add it to a file
        fprintf(save, name);

        crawler = crawler->next[0];
    }
    fclose(save);

    printf("\033[H\033[J");
    printf("\n+-------------------------3/3----------------------+");
    printf("\nSuccessfully saved the calendar in  [\033[1;35m%s\033[1;0m].",filename);
    printf("\nEnter anything to continue.");
    printf("\n+--------------------------------------------------+");
    printf("\n-> ");
    scanf("%s", verif);
}

void menuLoadFile(t_d_calendar** calendar)
{
    char answer[2];
    char filename[40];
    char verif[30];
    printf("\033[H\033[J");
    printf("\n+-------------------1/3-------------------+");
    printf("\nYou chose to load a calendar.");
    printf("\nEnter either [\033[1;35my\033[1;0m] to save or [\033[1;35mn\033[1;0m] to go back.");
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
    printf("\nPlease enter the name of the file which contains the calendar.");
    printf("\nPlease do not put special characters.");
    printf("\n+----------------------------------------------------------------+");
    printf("\n-> ");

    scanf("%40s",filename);

    FILE *save = fopen(filename, "r");
    // check if file exists
    if (save == NULL)
    {
        printf("This file doesn't exist.\n");
        scanf(" ");
        return;
    }

    // for each contact in calendar
    char buffer[70];
    char surname[30];
    char firstName[30];
    while (fgets(buffer, sizeof(buffer), save) != NULL)
    {
        strcpy(surname, strtok(buffer, " "));
        strcpy(firstName, strtok(buffer, " "));
        insertCalContact(calendar, createCalContact(createInfo(createContact(strdup(surname), strdup(firstName)))));
    }

    fclose(save);

    printf("\033[H\033[J");
    printf("\n+-------------------------3/3----------------------+");
    printf("\nSuccessfully loaded the calendar");
    printf("\nEnter anything to continue.");
    printf("\n+--------------------------------------------------+");
    printf("\n-> ");
    scanf("%s", verif);
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
        printf("\n[\033[1;35m1\033[1;0m] Credits");
        printf("\n[\033[1;35m2\033[1;0m] Calculation Time");
        printf("\n[\033[1;35m3\033[1;0m] Quit the Info Menu");
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
                printf("\n-> \033[1;35mAntoine IGLESIAS-TALLON\033[1;0m (Still MIA)");
                printf("\n-> \033[1;35mAntoine MEUNIER\033[1;0m (No link to the school principal)");
                printf("\n-> \033[1;35mNassim AININE\033[1;0m (Not an Antoine)");
                printf("\n+-----------------------------------------------------------+");
                printf("\n-> ");
                fflush(stdin);
                scanf("%s", verif);
                break;
            case '2':
                printf("\033[H\033[J");
                printf("\n+---------------------------------------------------+");
                printf("\nThe calculations for searching for a contact :");
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


