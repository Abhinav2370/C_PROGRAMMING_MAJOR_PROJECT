#include <stdio.h>
#include <string.h>
#include "ticket.h"

// Famous Indian trains with prices (AC/Non-AC per person)
struct TrainPrice trains[] = {
    {"Shatabdi Express", 1200.0, 800.0},
    {"Rajdhani Express", 2500.0, 1800.0},
    {"Duronto Express", 2000.0, 1400.0},
    {"Vande Bharat", 3000.0, 2000.0},
    {"Garib Rath", 900.0, 600.0},
    {"Tejas Express", 1500.0, 1000.0}
};
#define NUM_TRAINS 6

void showTrains() {
    printf("\n===== Available Trains & Prices (Per Person) =====\n");
    printf("%-20s %-10s %-10s\n", "Train Name", "AC", "Non-AC");
    printf("---------------------------------------------\n");
    for (int i = 0; i < NUM_TRAINS; i++) {
        printf("%-20s Rs.%-9.0f Rs.%-9.0f\n", 
               trains[i].name, trains[i].ac_price, trains[i].non_ac_price);
    }
    printf("\n");
}

void bookTicket(struct Ticket t[]) {
    static int count = 0;
    
    if (count >= MAX) {
        printf("\nAll tickets are booked!\n");
        return;
    }
    
    showTrains();
    
    printf("\nEnter Name: ");
    scanf("%s", t[count].name);
    
    printf("Enter Train Name: ");
    scanf("%s", t[count].train);
    
    printf("Enter Age: ");
    scanf("%d", &t[count].age);
    
    printf("AC (1) or Non-AC (0)? ");
    int ac_choice;
    scanf("%d", &ac_choice);
    
    // Find train price
    float price = 0;
    for (int i = 0; i < NUM_TRAINS; i++) {
        if (strcmp(trains[i].name, t[count].train) == 0) {
            price = (ac_choice) ? trains[i].ac_price : trains[i].non_ac_price;
            break;
        }
    }
    
    if (price == 0) {
        printf("Train not found! Using default price Rs.1000\n");
        price = 1000.0;
    }
    
    t[count].price = price;
    t[count].booked = 1;
    printf("\nTicket Booked! Ticket ID = %d\n", count + 1);
    printf("Total Price: Rs.%.2f\n", price);
    count++;
}

void viewTickets(struct Ticket t[]) {
    printf("\n===== All Booked Tickets =====\n");
    printf("%-5s %-15s %-20s %-5s %-10s\n", "ID", "Name", "Train", "Age", "Price");
    printf("----------------------------------------------------\n");
    
    int found = 0;
    for (int i = 0; i < MAX; i++) {
        if (t[i].booked == 1) {
            printf("%-5d %-15s %-20s %-5d Rs.%-9.2f\n", 
                   i+1, t[i].name, t[i].train, t[i].age, t[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No tickets booked yet.\n");
    }
}

void cancelTicket(struct Ticket t[]) {
    int id;
    printf("\nEnter Ticket ID to cancel: ");
    scanf("%d", &id);

    if (id < 1 || id > MAX || t[id - 1].booked == 0) {
        printf("\nInvalid Ticket ID!\n");
    } else {
        printf("Cancelled Ticket - Refund: Rs.%.2f\n", t[id - 1].price);
        t[id - 1].booked = 0;
        printf("Ticket %d cancelled.\n", id);
    }
}
