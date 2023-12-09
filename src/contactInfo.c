#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../includes/contactInfo.h"
#include "../includes/menu.h"

t_d_contactInfo* createInfo(t_d_contact contact)
{
    t_d_contactInfo* newInfo = (t_d_contactInfo*) malloc(sizeof(t_d_contactInfo));

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

void deleteInfo(t_d_contactInfo** info)
{
    free((*info)->key);
    free((*info)->firstAppointment);
    free(*info);
    *info = NULL;
}

void displayInfo(t_d_contactInfo* info)
{
    if (info == NULL)
    {
        printf("Contact Info doesn't exist.\n");
        return;
    }

    displayContact(info->contact);
    printf("Known as [%s]\n", info->key);
    printf("Appointements :\n");
}

void addAppointement(t_d_contactInfo info, t_d_appointment appointment)
{

}