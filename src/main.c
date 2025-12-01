#include "railway.h"

int main() {
    struct Ticket t[MAX];
    int choice;

    init(t);

    while (1) {
        printf("\n--- Railway Ticket Menu ---\n");
        printf("1. Display Tickets\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Show Train List\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: display(t); break;
            case 2: book(t); break;
            case 3: cancel(t); break;
            case 4: showTrains(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

