#include <stdio.h> 
#include <stdlib.h>

// #include "./representbus.h"

#ifndef REP
    #define REP
    #include"./representbus.h"
#endif

void userdetails(int seat,int fare);
void bookSeat(struct Bus *bus);

// Function to book a seat on a given bus
void bookSeat(struct Bus *bus) {
    int seat, fare;
    printf("Enter the seat number (1-20): ");
    scanf("%d", &seat);
    if (seat < 1 || seat > MAX_SEATS) {
        printf("Invalid seat number\n");
        return;
    }
    else if (bus->seats[seat - 1]==1) {
        printf("Seat already booked\n");
    } 
	else {
        bus->seats[seat - 1] = 1;
        printf("congratulation!!! \n your seat has been booked successfully.");
        userdetails(seat, bus->fare);
    }
}

void userdetails(int seat, int fare){
	char name[30],phone[20];
	int age;
	printf("Enter your name: ");
	scanf("%s",&name);
	printf("Enter your age: ");
	scanf("%d",&age);
	printf("Enter your phone number: ");
	scanf("%s",&phone);
	FILE *fptr;
	fptr=fopen("userdetails.txt","w+");
	fprintf(fptr,"************Ticket**************\n");
	fprintf(fptr,"Name: %s\n",name);
	fprintf(fptr,"Age: %d\n",age);
	fprintf(fptr,"Phone Number: %s\n",phone);
	fprintf(fptr,"Seat Number: %d\n",seat);
	fclose(fptr);
	FILE *fp;
	char temp[200];
	fp=fopen("userdetails.txt","r");
	while(fscanf(fp,"%s",temp)!=EOF){
		printf("\n%s",temp);
	}
	fclose(fp);
}
