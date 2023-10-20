#include<stdio.h>
#include<string.h>

#define MAX_SEATS 20
#define MAX_BUSES 10

// Structure to represent a bus
struct Bus {
    int id;
    char route[50];
    int fare;
    int seats[MAX_SEATS];
};