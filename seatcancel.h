#include<stdio.h>
#include<string.h>

// #include "./representbus.h"
#ifndef REP
    #define REP
    #include"./representbus.h"
#endif

// Function to cancel a seat on a given bus
void cancelSeat(struct Bus bus) {
    int seat;
    printf("Enter the seat number (1-20): ");
    scanf("%d", &seat);
    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number\n");
        return;
    }
    if (bus.seats[seat]==seat) {
        bus.seats[seat] = 0;
        printf("Seat cancelled successfully\n");
    } 
	else {
        printf("Seat already unbooked\n");
    }
}
// void cancelSeat(struct Bus bus);
