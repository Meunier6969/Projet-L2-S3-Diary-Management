#include "contact.h"
#include "appointment.h"

typedef struct calendar
{
    t_d_contact contact;
    char *key;

    t_d_appointment *firstAppointment;
};
