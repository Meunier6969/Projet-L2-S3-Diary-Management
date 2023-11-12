#include <stdio.h>
#include "menu.h"

void displayMenu()
{
    printf("+-------------Diary Managment--------------+\n");
    printf("+------------------------------------------+\n");
    printf("+-  Welcome, what would you like to do ?  -+\n");
    printf("[1] Create a Contact\n");
    printf("[2] Create an Appointment\n");
    printf("[3] Delete an Appointment\n");
    printf("[4] View Contact Appointment\n");
    printf("[5] Search for a Contact\n");
    printf("[6] Save the Appointment File\n");
    printf("[7] Load Appointment File\n");
    printf("[8] Info\n");
    printf("[9] Quit\n");
}

int getInput(void)
{
    printf("Enter a number : ");
    // get le input
    // potentiellement appeller la fonction necessaire mais jsp tho
}
