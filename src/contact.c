#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../includes/contact.h"
#include "../includes/menu.h" // access to _MAX_LENGTH

t_d_contact* createContact(char *surname, char *firstName)
{
    t_d_contact* newContact = (t_d_contact*) malloc(sizeof(t_d_contact));

    newContact->surname = surname;
    newContact->firstName = firstName;

    return newContact;
}

void deleteContact(t_d_contact* contact)
{
    free(contact);
}

void displayContact(t_d_contact contact)
{
    printf("Contact : [%s] [%s]\n", contact.surname, contact.firstName);
}