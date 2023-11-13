#include "contact.h"
#include "appointment.h"

typedef struct s_d_calendar
{
    t_d_contact contact;
    char *key;

    t_d_appointment *firstAppointment;
} t_d_calendar;
