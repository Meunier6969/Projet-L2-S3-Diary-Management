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
        fprintf(stderr, "fuck you");
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
        printf("%s %ld ", contact->contact->key, i);
        // if not at head
        if (previous != NULL)
        {
            printf("NOT AT HEAD");
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
            printf("NOT AT TAiL");
            
            crawler = contact->next[0];

            if (crawler == NULL)
            {

            }

            while (crawler != NULL && crawler->level < i)
            {
                crawler = crawler->next[0];
            }

            closest = crawler;

            /*
            while (crawler->level >= i) // warning if next == NULL
            {
                crawler = crawler->next[0];
                if (crawler == NULL)
                {
                    closest = NULL;
                    break;
                }
            } 
            */

            contact->next[i-1] = closest;
        }
            /* code */
        
        printf("\n");

        continue;

        // if (closest == NULL) printf("behind is noone - ");
        // else printf("behind is %s - ", closest->contact->key);

        // to the front
        

        if (closest == NULL) printf("in front is noone - ");
        else printf("in front is %s - ", closest->contact->key);
        printf("for %s at level %ld\n", contact->contact->key, i);

        // for each level of contact
        // start from head
        // find closest calcon behind that see => level of calcon >= level
        // closest.next[level] = contact
        // start from contact
        // find closest in front that see => level of calcon >= level
        // contact.next[level] = closest

    }

    printf("__%s__\n", contact->contact->key);
    showCalendar(*calendar);

}

void changeCalContact(t_d_calcontact* previous, int newLevel)
{

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
    t_d_calcontact* crawler = calendar->head;

    while (crawler != NULL)
    {
        displayCalContact(crawler);
        crawler = crawler->next[0];
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