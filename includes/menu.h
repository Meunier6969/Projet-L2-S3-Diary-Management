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
void menuSearchContact(); //Will also need a searchcontact function.
void menuDeleteContact();
void menuDeleteAppointment(); //Will probably need the calendar in entry.
void menuSaveFile();
void menuLoadFile();
void menuInfo();

#endif