#ifndef _INCLUDE_MENU
#define _INCLUDE_MENU

#define _MAX_LENGTH 100
#include "calendar.h"

void displayMenu(void);
void menuQuit();
char *scanString(int);

//All the menu because life isn't hard enough as it is.
t_d_calcontact* menuCreateContact();
void menuCreateAppointment(t_d_calendar* Calendar);
void menuSeeAllContacts(t_d_calendar*);
t_d_calcontact* menuSearchContact(t_d_calendar* calendar);
void menuDeleteContact();
void menuDeleteAppointment(); //Will probably need the calendar in entry.
void menuSaveFile();
void menuLoadFile();
void menuInfo();

#endif