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

void deleteAppointment()
{

}

void addNextAppointment(t_d_appointment* head, t_d_appointment* toAdd)
{
    if (head == NULL)
    {
        head = toAdd;
        return;
    }

    // go through the list until NULL
    t_d_appointment* crawler = head;

    while (crawler->next != NULL)
        crawler = crawler->next;
    
    // add
    crawler->next = toAdd;
}

void showApp(t_d_appointment* head)
{
    t_d_appointment* curapp = head;

    if (curapp == NULL)
    {
        printf("no\n");
        return;
    }

    do
    {
        printf("------------------\n");
        printf("Date : %d/%d/%d\nDate Time : %d:%d\nAppointment Length : %d:%d\nPurpose : %s\n",
            curapp->date.day, curapp->date.month, curapp->date.year,
            curapp->appointmentTime.hours, curapp->appointmentTime.minutes,
            curapp->appointmentLength.hours, curapp->appointmentLength.minutes,
            curapp->purpose);
        curapp = curapp->next;
    } while (curapp != NULL);
}