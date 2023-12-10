#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    t_d_calcontact* newCalContact = (t_d_calcontact*) malloc(sizeof(t_d_calcontact));

    newCalContact->contact = contact;
    newCalContact->level = 0;   // default values, changed by insertCalContact
    newCalContact->next = malloc(4 * sizeof(t_d_calcontact*)); // and changeCalContact

    for (size_t i = 0; i < 4; i++)
        newCalContact->next[i] = NULL;

    return newCalContact;
}

void insertCalContact(t_d_calendar** calendar, t_d_calcontact* contact)
{
    // only level 0 for now
    if (calendar == NULL || *calendar == NULL)
    {
        fprintf(stderr, "Calendar doesn't exist.");
        return;
    }

    // find the place to insert
    t_d_calcontact *crawler, *previous;
    crawler = (*calendar)->head;
    previous = NULL;

    while (crawler != NULL && strcmp(contact->contact->key, crawler->contact->key) > 0)
    {
        previous = crawler;
        crawler = crawler->next[0];
    }
    
    // empty or head
    if (previous == NULL)
    {
        contact->next[0] = (*calendar)->head;
        (*calendar)->head = contact;
    }
    else if (crawler == NULL && previous != NULL)
    {
        contact->next[0] = NULL;
        previous->next[0] = contact;
    }
    else 
    {   
        contact->next[0] = previous->next[0];
        previous->next[0] = contact;
    }

    // find the level (by comparing with previous)
    contact->level = 4;

    if (previous != NULL)
    {   
        for (size_t i = 0; i < 3; i++)
        {
            if (previous->contact->key[i] == contact->contact->key[i])
                contact->level--;
            else
                break;
        }
    }

    if (contact->next[0] != NULL)
    {
        contact->next[0]->level = 4;

        for (size_t i = 0; i < 3; i++)
        {
            if (contact->contact->key[i] == contact->next[0]->contact->key[i])
                contact->next[0]->level--;
            else
                break;
        }
    }

    // updating the pointers
    t_d_calcontact* closest = (*calendar)->head;

    for (size_t i = contact->level; i > 1; i--)
    {
        // if not at head
        if (previous != NULL)
        {
            crawler = (*calendar)->head;
            while (crawler != contact)
            {
                if (crawler->level >= i) closest = crawler;
                crawler = crawler->next[0];
            } 
            closest->next[i-1] = contact;
        }
        
        // if not at tail
        if (contact->next[0] != NULL)
        {   
            crawler = contact->next[0];
            while (crawler != NULL && crawler->level < i)
            {
                crawler = crawler->next[0];
            }
            closest = crawler;

            contact->next[i-1] = closest;
        }
        
        printf("\n");
    }
}

void deleteCalContact(t_d_calendar* calendar, t_d_contactinfo* contact)
{
    
}

t_d_calcontact* searchCalContact(t_d_calendar* calendar, char* key)
{
    return NULL;
}

void showCalendar(t_d_calendar* calendar)
{
    int i = 1;
    t_d_calcontact* crawler = calendar->head;

    if (crawler == NULL)
    {
        printf("Calendar is empty.\n");
    }

    while (crawler != NULL)
    {
        printf("%d - ", i);
        displayInfoShort(crawler->contact);
        crawler = crawler->next[0];
        i++;
    }
}

void displayCalContact(t_d_calcontact* contact)
{
    if (contact == NULL)
    {
        printf("Contact doesn't exist.\n");
        return;
    }

    printf("%d | ", contact->level);
    printf("%s\t", contact->contact->key);

    for (size_t i = 0; i < 4; i++)
    {
        if (contact->next[i] == NULL)   printf("[noone]");
        else                            printf("[%s]", contact->next[i]->contact->key);
    }
    

    printf("\n");
}