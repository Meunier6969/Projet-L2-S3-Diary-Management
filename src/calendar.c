#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"

t_d_calendar* createCalendar(t_d_contact contact)
{
    t_d_calendar* newCalendar = (t_d_calendar*) malloc(sizeof(t_d_calendar));

    newCalendar->contact = contact;
    newCalendar->firstAppointment = NULL;

    char* newKey = calloc(_MAX_LENGTH, sizeof(char));
    strcat(newKey, contact.surname);
    strcat(newKey, "_");
    strcat(newKey, contact.firstName);

    for(int i = 0; newKey[i]; i++)
        newKey[i] = tolower(newKey[i]);

    newCalendar->key = newKey;

    return newCalendar;
}

void deleteCalendar(t_d_calendar* calendar)
{
    free(calendar->key);
    free(calendar);
}

void displayCalendar(t_d_calendar calendar)
{
    displayContact(calendar.contact);
    printf("Known as [%s]\n", calendar.key);
    printf("Appointements :\n");
}

void addAppointement(t_d_calendar calendar, t_d_appointment appointment)
{

}