#include<stdio.h>
#include<string.h>

#include "./delete.h"
#ifndef REP
    #define REP
    #include"./representbus.h"
#endif

void deleteBus(struct Bus buses[], int *count, int id) {
    int index = -1;
    int i;
    for(i = 0; i < *count; i++) {
        if (buses[i].id == id) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Bus not found\n");
    } else {
    	int i;
        for(i = index; i < (*count) - 1; i++) {
            buses[i] = buses[i + 1];
        }
        (*count)--;
        printf("Bus deleted successfully\n");
    }
}