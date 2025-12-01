#ifndef TICKET_H
#define TICKET_H

#define MAX 5

struct Ticket {
    char name[30];
    char train[30];
    int age;
    int booked;   // 1 = booked, 0 = empty
    float price;  // Ticket price
};

// Famous trains with predefined prices (AC/Non-AC per person)
struct TrainPrice {
    char name[30];
    float ac_price;
    float non_ac_price;
};

extern struct TrainPrice trains[];

// Function prototypes
void bookTicket(struct Ticket t[]);
void viewTickets(struct Ticket t[]);
void cancelTicket(struct Ticket t[]);
void showTrains();

#endif
