#ifndef _INCLUDE_CONTACT
#define _INCLUDE_CONTACT
#include "appointment.h"

typedef struct s_d_contact
{
    char *surname;
    char *firstName;
} t_d_contact;

t_d_contact* createContact(char *, char *);
void deleteContact(t_d_contact*);
void displayContact(t_d_contact);

#endif