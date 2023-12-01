#include <stdio.h>
#include <stdlib.h>

#include "../includes/calendar.h"
#include "../includes/menu.h"
// #include "../includes/list.h"
// #include "../includes/cell.h"
// #include "timer/timer.h"

int main()
{
    t_d_contact* bing = createContact("Bing", "Chilling");
    t_d_calendar* cal = createCalendar(*bing);

    displayCalendar(cal);
    deleteCalendar(&cal);
    deleteContact(bing);
    displayCalendar(cal);

    return 0;
}
