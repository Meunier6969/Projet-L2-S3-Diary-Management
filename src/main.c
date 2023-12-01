#include <stdio.h>
#include <stdlib.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "timer/timer.h"

int main()
{
    char* name;
    name = scanString(30);

    t_d_contact *bing = createContact(name, "Chilling");
    t_d_calendar* cal = createCalendar(*bing);

    displayCalendar(cal);
    deleteCalendar(&cal);
    deleteContact(bing);

    return 0;
}
