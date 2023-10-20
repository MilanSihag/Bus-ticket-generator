#include<stdio.h>
#include<string.h>

// #include "./representbus.h"
#ifndef REP
    #define REP
    #include"./representbus.h"
#endif


// Function to display all the available buses for a given route
void displayBuses(struct Bus buses[], int count, char route[]) {
    int found = 0;
    int i;
    for(i = 0; i < count; i++) {
        if (strcmp(buses[i].route, route) == 0) {
        	printf("Available bus for the route %s is:\n",route);
            printf("Bus ID: %d, Fare: %d\n", buses[i].id, buses[i].fare);
            found = 1;
            printf("The desired seat is booked");
        }
    }
    if(found==0){
        printf("No buses available for route %s\n", route);
    }
}
// void displayBuses(struct Bus buses[], int count, char route[]);