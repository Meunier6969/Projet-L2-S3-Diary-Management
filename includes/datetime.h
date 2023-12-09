#ifndef _INCLUDE_DATETIME
#define _INCLUDE_DATETIME

typedef struct s_d_date
{
    int day;
    int month;
    int year; // In it's entirety, not just 23, but 2023 (In case we go back in time u know)
} t_d_date;

typedef struct s_d_length
{
    int hours;
    int minutes;
} t_d_length;

t_d_date createDate(int, int, int);
t_d_length createLength(int, int);

#endif