#include <stdlib.h>
#include <stdio.h>
#include "../includes/calendar.h"
#include "../includes/contactinfo.h"

t_d_calendar* createCalendar(int maxLevel)
{
    t_d_calendar* newCalendar = (t_d_calendar*) malloc(sizeof(t_d_calendar));

    newCalendar->head = NULL;
    newCalendar->maxLevel = maxLevel;

    return newCalendar;
}

t_d_calcontact* createCalContact(t_d_contactinfo* contact)
{
    t_d_calcontact* newCalContact;

    newCalContact->contact = contact;
    newCalContact->level = 0;   // default values, changed by insertCalContact
    newCalContact->next = malloc(4 * sizeof(t_d_calcontact*)); // and changeCalContact

    return newCalContact;
}

void insertCalContact(t_d_calendar* calendar, t_d_calcontact* contact)
{
    // only level 0 for now
    if (calendar == NULL)
    {
        fprintf(stderr, "fuck you");
        return;
    }

    contact->next[0] = calendar->head;
    calendar->head = contact;
    
}

void changeCalContact(t_d_calendar* calendar, t_d_calcontact* contact, int newLevel)
{
    
}

void deleteCalContact(t_d_calendar* calendar, t_d_contactinfo* contact)
{
    
}

t_d_calcontact* searchCalContact(t_d_calendar* calendar, char* key)
{
    
}

void showCalendar(t_d_calendar* calendar)
{
    t_d_calcontact* crawler = calendar->head;

    while (crawler != NULL)
    {
        displayInfoShort(crawler->contact);
        crawler = crawler->next[0];
    }
}
