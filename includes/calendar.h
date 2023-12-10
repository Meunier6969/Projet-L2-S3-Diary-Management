#ifndef _INCLUDE_CALENDAR
#define _INCLUDE_CALENDAR

#include "contactinfo.h"

// multi level linked list

typedef struct s_d_calendarcontact
{
    t_d_contactinfo* contact;

    struct s_d_calendardontact** next;
    int level;
} t_d_calcontact;

typedef struct s_d_calendar
{
    t_d_calcontact* head; // one * because first contact is garanted to be at maxLevel
    int maxLevel;
} t_d_calendar;

t_d_calendar* createCalendar(int maxLevel);
t_d_calcontact* createCalContact(t_d_contactinfo* contact);

void insertCalContact(t_d_calendar* calendar, t_d_calcontact* contact);
void changeCalContact(t_d_calendar* calendar, t_d_calcontact* contact, int newLevel);
void deleteCalContact(t_d_calendar* calendar, t_d_contactinfo* contact);

t_d_calcontact* searchCalContact(t_d_calendar* calendar, char* key);

void showCalendar(t_d_calendar* calendar);

#endif