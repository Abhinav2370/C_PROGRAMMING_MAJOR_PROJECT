#ifndef RAILWAY_H
#define RAILWAY_H

#include <stdio.h>
#include <string.h>

#define MAX 5   // max 5 tickets
#define TRAIN_COUNT 3

struct Ticket {
    char name[30];
    char train[30];
    int age;
    int booked;   // 1 = booked, 0 = empty
};

// Function declarations
void init(struct Ticket t[]);
void display(struct Ticket t[]);
void book(struct Ticket t[]);
void cancel(struct Ticket t[]);
void showTrains();

#endif
