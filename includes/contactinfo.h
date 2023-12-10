#ifndef _INCLUDE_CONTACTINFO
#define _INCLUDE_CONTACTINFO

#include "contact.h"
#include "appointment.h"

typedef struct s_d_contactinfo
{
    t_d_contact contact;
    char *key;

    t_d_appointment *firstAppointment;
} t_d_contactinfo;

t_d_contactinfo* createInfo(t_d_contact);
void deleteInfo(t_d_contactinfo**);
void displayInfo(t_d_contactinfo*);
void displayInfoShort(t_d_contactinfo*);

void addAppointement(t_d_contactinfo*, t_d_appointment*);

#endif