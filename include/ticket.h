
#ifndef TICKET_H
#define TICKET_H

#define MAX 5

struct Ticket {
    char name[30];
    char train[30];
    int age;
    int booked;     // 1 = booked, 0 = empty
};

// Function declarations
void initializeTickets(struct Ticket t[]);
void bookTicket(struct Ticket t[], int *count);
void viewTickets(struct Ticket t[]);
void cancelTicket(struct Ticket t[]);

#endif
