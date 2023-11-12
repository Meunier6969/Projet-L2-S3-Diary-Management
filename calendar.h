#ifndef _INCLUDE_CALENDAR
#define _INCLUDE_CALENDAR

#include "appointement.h"
#include "contact.h"



typedef struct s_d_calendar // I don't know if it's what's asked srry
{
    t_d_contact contact;
    t_d_appointment **appointments;
    int nbLevels;
} t_d_calendar;

#endif