#ifndef _INCLUDE_APPOINTEMENT
#define _INCLUDE_APPOINTEMENT

#include "datetime.h"

typedef struct s_d_appointment
{
    t_d_date date;

    t_d_length appointmentTime;

    t_d_length appointmentLength;

    char *purpose; // Information on the appointment. Can be long, so depends I guess.

    struct s_d_appointment* next;
} t_d_appointment;

t_d_appointment* createAppointment(t_d_date, t_d_length, t_d_length, char*);

void deleteAppointment();
void addNextAppointment(t_d_appointment**, t_d_appointment*);

void showAppointements(t_d_appointment* head);

#endif