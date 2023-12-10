#include <stdlib.h>
#include <stdio.h>

#include "../includes/appointment.h"

t_d_appointment* createAppointment(t_d_date date, t_d_length time, t_d_length length, char* purpose)
{
    t_d_appointment* newAppointment = (t_d_appointment*) malloc(sizeof(t_d_appointment));

    newAppointment->date = date;
    newAppointment->appointmentTime = time;
    newAppointment->appointmentLength = length;

    newAppointment->purpose = purpose;

    newAppointment->next = NULL;

    return newAppointment;
}

void deleteAppointment(t_d_appointment** head, int index)
{
    if (head == NULL || *head == NULL)
    {
        printf("No appointmens to delete.\n");
        return;
    }
    

    if (index <= 0) 
    {
        printf("Invalid index (too low)\n");
        return;
    }

    // remove head
    if (index == 1)
    {
        t_d_appointment* toDelete = *head;
        *head = (*head)->next;
        free(toDelete);
        return;
    }
    
    // otherwise
    // we traverse the list until we get to the element before the one to delete
    // if previous->next is null, then the index was too big
    t_d_appointment* previous = *head;

    for (size_t i = 1; previous->next != NULL && i < index - 1; i++)
    {
        previous = previous->next;
    }

    if (previous->next == NULL)
    {
        printf("Invalid index (too high)\n");
        return;
    }   

    t_d_appointment* toDelete = previous->next;
    previous->next = previous->next->next;
    free(toDelete);
}

void addNextAppointment(t_d_appointment** head, t_d_appointment* toAdd)
{
    if (*head == NULL)
    {
        *head = toAdd;
        return;
    }

    // go through the list until NULL
    t_d_appointment* crawler = *head;

    while (crawler->next != NULL)
        crawler = crawler->next;
    
    // add
    crawler->next = toAdd;
}

void showAppointements(t_d_appointment* head)
{
    t_d_appointment* curapp = head;

    if (curapp == NULL)
    {
        printf("No Appointments.\n");
        return;
    }

    do
    {
        printf("+------------------------------------------+\n");
        printf("Date : %d/%d/%d\nDate Time : %d:%d\nAppointment Length : %d:%d\nPurpose : %s\n",
            curapp->date.day, curapp->date.month, curapp->date.year,
            curapp->appointmentTime.hours, curapp->appointmentTime.minutes,
            curapp->appointmentLength.hours, curapp->appointmentLength.minutes,
            curapp->purpose);
        curapp = curapp->next;
    } while (curapp != NULL);
}