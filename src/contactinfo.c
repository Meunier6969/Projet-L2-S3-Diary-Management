#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../includes/contactinfo.h"
#include "../includes/appointment.h"
#include "../includes/menu.h"

t_d_contactinfo* createInfo(t_d_contact contact)
{
    t_d_contactinfo* newInfo = (t_d_contactinfo*) malloc(sizeof(t_d_contactinfo));

    newInfo->contact = contact;
    newInfo->firstAppointment = NULL;

    char* newKey = calloc(_MAX_LENGTH, sizeof(char));
    strcat(newKey, contact.surname);
    strcat(newKey, "_");
    strcat(newKey, contact.firstName);

    for(int i = 0; newKey[i]; i++)
        newKey[i] = tolower(newKey[i]);

    newInfo->key = newKey;

    return newInfo;
}

void deleteInfo(t_d_contactinfo** info)
{
    free((*info)->key);
    free((*info)->firstAppointment);
    free(*info);
    *info = NULL;
}

void displayInfo(t_d_contactinfo* info)
{
    if (info == NULL)
    {
        printf("Contact Info doesn't exist.\n");
        return;
    }

    displayContact(info->contact);
    printf("Known as [%s]\n", info->key);
    printf("Appointements :\n");
    showAppointements(info->firstAppointment);
}

void displayInfoShort(t_d_contactinfo* info)
{
    if (info == NULL)
    {
        printf("Contact Info doesn't exist.\n");
        return;
    }

    printf("%s %s (%s)", info->contact.firstName, info->contact.surname, info->key);
    if (info->firstAppointment != NULL)
        printf(" - Has Appointments");
    printf("\n");
}

void addAppointement(t_d_contactinfo* info, t_d_appointment* appointment)
{
    addNextAppointment(&info->firstAppointment, appointment);
}