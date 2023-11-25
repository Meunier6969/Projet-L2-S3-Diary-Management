#ifndef _INCLUDE_CALENDAR
#define _INCLUDE_CALENDAR

#include "contact.h"
#include "appointment.h"

typedef struct s_d_calendar
{
    t_d_contact contact;
    char *key;

    t_d_appointment *firstAppointment;
} t_d_calendar;

t_d_calendar* createCalendar(t_d_contact);
void deleteCalendar(t_d_calendar*);
void displayCalendar(t_d_calendar);

void addAppointement(t_d_calendar, t_d_appointment);

#endif