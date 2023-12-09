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

t_d_contactinfo* createCalendar(t_d_contact);
void deleteCalendar(t_d_contactinfo**);
void displayCalendar(t_d_contactinfo*);

void addAppointement(t_d_contactinfo, t_d_appointment);

#endif