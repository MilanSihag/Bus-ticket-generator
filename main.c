#include <stdio.h>
#include <string.h>

#ifndef REP
#define REP
#include "./representbus.h"
#endif

#include "./delete.h"
#include "./display.h"
#include "./seatcancel.h"

#include "./userdetails.h"
#include "./update.h"

// gcc -c .\main.c .\representbus.h .\display.h .\seatcancel.h .\update.h .\userdetails.h
// gcc -c .\display.c .\display.h
// gcc -c .\update.c .\update.h
// gcc -c .\userdetails.c .\userdetails.h
// gcc -c .\seatcancel.c .\seatcancel.h
// gcc -c .\delete.c .\delete.h

// Main function
int main()
{
    // printf("Hello");

    struct Bus buses[MAX_BUSES];
    int count = 0;
    int choice, id;
    char route[50];

    // Populate some initial data
    struct Bus bus1 = {1, "AMRITSAR - JALANDHAR", 500, {0}};
    struct Bus bus2 = {2, "AMRITSAR - PHAGWARA", 400, {0}};
    struct Bus bus3 = {3, "AMRITSAR - LUDHIYANA", 300, {0}};
    struct Bus bus4 = {4, "AMRITSAR - HOSHIYARPUR", 455, {0}};
    struct Bus bus5 = {5, "AMRITSAR - CHAHERU", 600, {0}};
    struct Bus bus6 = {6, "AMRITSAR - MAHERU", 1007, {0}};

    buses[count++] = bus1;
    buses[count++] = bus2;
    buses[count++] = bus3;
    buses[count++] = bus4;
    buses[count++] = bus5;
    buses[count++] = bus6;

    printf("\n");
    printf("\n||**************************************************||\n");
    printf("            Electronic Bus Ticket Generator\n");
    printf("||****************************************************||\n");
    printf("\n");
    printf("1. Display available buses for a route\n");
    printf("2. Add new bus\n");
    printf("3. Book seat\n");
    printf("4. Cancel seat\n");
    printf("5. Delete a particular bus\n");
    printf("6. Update a particular bus details\n");
    printf("7. Exit\n");
    printf("\n");
    printf("||^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^||\n");
    printf("\n");
    printf("Enter your choice from the options (1-7): ");
    scanf("%d", &choice);
    printf("\n");

    printf("\n");
    // Menu-driven program loop
    while (choice < 7)
    {
        switch (choice)
        {
        case 1:
            printf(" The routes are as follows :\nAMRITSAR - JALANDHAR , AMRITSAR - PHAGWARA , AMRITSAR - LUDHIYANA , AMRITSAR - HOSHIYARPUR , AMRITSAR - CHAHERU ,AMRITSAR - MAHERU\n");
            printf(" ::Enter the route: ");
            scanf("%s", route);
            displayBuses(buses, count, route);
            break;
        case 2:
            addBus(buses, count);
            break;
        case 3:
            printf("::Enter the bus ID of your choice :  ");
            scanf("%d", &id);
            int i;
            for (i = 0; i < count; i++)
            {
                if (buses[i].id == id)
                {
                    bookSeat(&buses[i]);
                    break;
                }
            }
            break;
        case 4:
            printf("::Enter the bus ID as per the records: ");
            scanf("%d", &id);

            for (i = 0; i < count; i++)
            {
                if (buses[i].id == id)
                {
                    cancelSeat(buses[i]);
                    break;
                }
            }
            break;
        case 5:
            printf("::Enter the bus ID: ");
            scanf("%d", &id);
            deleteBus(buses, &count, id);
            break;
        case 6:
            printf("::Enter the bus ID: ");
            scanf("%d", &id);
            updateBus(buses, count, id);
            break;
        case 7:
            printf("Exiting from the interface...\n");
            break;
        default:
            printf("!!!!Invalid choice please select valid option!!!!\n");
            break;
        }
        printf("\n");
        printf("\n||***************************************************||\n");
        printf("            Electronic Bus Ticket Generator\n");
        printf("||*****************************************************||\n");
        printf("\n");
        printf("1. Display available buses for a route\n");
        printf("2. Add new bus into the menu\n");
        printf("3. Book seats as per your choice\n");
        printf("4. Cancel seats \n");
        printf("5. Delete a particular bus from list\n");
        printf("6. Update a particular bus details from list\n");
        printf("7. Exit\n");
        printf("\n");
        printf("||     ******************************************       ||\n");
        printf("\n");
        printf("Enter your choice from the options(1-7): ");
        scanf("%d", &choice);
        printf("\n");

        printf("\n");
    }
}