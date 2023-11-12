#ifndef _INCLUDE_CELL
#define _INCLUDE_CELL

// Part 1 & 2
// Structure of a cell.
typedef struct s_d_cell
{
    int value;
    int nbLevels;
    struct s_d_cell **next;
} t_d_cell; 

t_d_cell* createCell(int value, int height);
void displayCell(t_d_cell cell);

// Part 3
typedef struct s_d_contact
{
    char surname[30];
    char firstName[30];
} t_d_contact; 

typedef struct s_d_appointment
{
    int day;
    int month;
    int year;           //In it's entirety, not just 23, but 2023 (In case we go back in time u know)

    int app_hour;       //Appointment time
    int app_minute;

    int lenght_hour;    //Length of appointment
    int lenght_minute;

    char purpose[];     //Information on the appointment. Can be long, so depends I guess.
} t_d_appointment; 

char *scanString(void); //"Performs the input and returns a dynamic array" whatever that means.
#endif