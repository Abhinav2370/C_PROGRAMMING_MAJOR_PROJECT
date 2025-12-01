#include <stdio.h>
#include "ticket.h"

int main() {
    struct Ticket t[MAX];
    
    for (int i = 0; i < MAX; i++) {
        t[i].booked = 0;
    }

    int choice;
    
    while (1) {
        printf("\n===== Railway Ticket Management System =====\n");
        printf("1. View Available Trains\n");
        printf("2. Book Ticket\n");
        printf("3. View All Tickets\n");
        printf("4. Cancel Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            showTrains();
        }
        else if (choice == 2) {
            bookTicket(t);
        }
        else if (choice == 3) {
            viewTickets(t);
        }
        else if (choice == 4) {
            cancelTicket(t);
        }
        else if (choice == 5) {
            printf("\nExiting... Thank you!\n");
            break;
        }
        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
