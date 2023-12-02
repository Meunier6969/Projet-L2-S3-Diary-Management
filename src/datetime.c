#include <stdlib.h>

#include "../includes/datetime.h"

t_d_date *createDate(int day, int month, int year)
{
    t_d_date *newDate = (t_d_date*) malloc(sizeof(t_d_date));

    newDate->day = day;
    newDate->month = month;
    newDate->year = year;

    return newDate;
}

t_d_length *createLength(int hours, int minutes)
{
    t_d_length *newLength = (t_d_length*) malloc(sizeof(t_d_length));

    newLength->hours = hours;
    newLength->minutes = minutes;

    return newLength;
}