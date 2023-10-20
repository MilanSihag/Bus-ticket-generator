#include <stdio.h>
#include <string.h>

// #include "./representbus.h"

#ifndef REP
    #define REP
    #include"./representbus.h"
#endif
#include "./update.h"

// Function to add a new bus to the system
void addBus(struct Bus buses[], int count) {
    if (count == MAX_BUSES) {
        printf("Max buses limit reached\n");
        return;
    }
    struct Bus NEWbus;
    printf("Enter the route: ");
    scanf("%s", &NEWbus.route);
    printf("Enter the fare: ");
    scanf("%d", &NEWbus.fare);
    NEWbus.id = count + 1;
    int i;
    for(i = 0; i < MAX_SEATS; i++) {
        NEWbus.seats[i] = 0;
    }
    buses[count] = NEWbus;
    count++;
    printf("Bus added successfully with ID %d\n", NEWbus.id);
}

// Function to update a particular bus
void updateBus(struct Bus buses[], int count, int id)
{
    int index = -1;
    int i;
    for (i = 0; i < count; i++)
    {
        if (buses[i].id == id)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        printf("Bus not found\n");
    }
    else
    {
        struct Bus bus = buses[index];
        printf("Enter the new route: ");
        scanf("%s", bus.route);
        printf("Enter the new fare: ");
        scanf("%d", &bus.fare);
        buses[index] = bus;
        printf("Bus details updated successfully\n");
    }
}