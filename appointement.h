#ifndef _INCLUDE_APPOINTEMENT
#define _INCLUDE_APPOINTEMENT

#define _MAX_STRING 100

typedef struct s_d_appointment
{
    int day;
    int month;
    int year; // In it's entirety, not just 23, but 2023 (In case we go back in time u know)

    int app_hour; // Appointment time
    int app_minute;

    int lenght_hour; // Length of appointment
    int lenght_minute;

    char *purpose; // Information on the appointment. Can be long, so depends I guess.
} t_d_appointment;

#endif