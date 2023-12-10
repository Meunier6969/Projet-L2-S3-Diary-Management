#ifndef _INCLUDE_MENU
#define _INCLUDE_MENU

#define _MAX_LENGTH 100

void displayMenu(void);
void menuQuit();
char *scanString(int);

//All the menu because life isn't hard enough as it is.
void menuCreateContact();
void menuCreateAppointment();
void menuSeeAllContacts();
void menuSearchContact(); //Will also need a searchcontact function.
void menuDeleteContact();
void menuDeleteAppointment(); //Will probably need the calendar in entry.
void menuSaveFile();
void menuLoadFile();
void menuInfo();

#endif