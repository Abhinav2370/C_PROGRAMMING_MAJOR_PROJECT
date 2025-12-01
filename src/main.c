
#include <stdio.h>
#include <string.h>

#define MAX 5  

struct Ticket {
    char name[30];
    char train[30];
    int age;
    int booked;   // 1 = booked, 0 = empty
};

int main() {
    struct Ticket t[MAX];
    int choice;
    int count = 0;

    
    for (int i = 0; i < MAX; i++) {
        t[i].booked = 0;
    }

    while (1) {
        printf("\n===== Railway Ticket Management System =====\n");
        printf("1. Book Ticket\n");
        printf("2. View All Tickets\n");
        printf("3. Cancel Ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

       
        if (choice == 1) {
            if (count >= MAX) {
                printf("\nAll tickets are booked!\n");
            } else {
                printf("\nEnter Name: ");
                scanf("%s", t[count].name);

                printf("Enter Train Name: ");
                scanf("%s", t[count].train);

                printf("Enter Age: ");
                scanf("%d", &t[count].age);

                t[count].booked = 1;
                printf("\nTicket Booked! Ticket ID = %d\n", count + 1);
                count++;
            }
        }

        
        else if (choice == 2) {
            printf(" All Booked Tickets\n");

            int found = 0;
            for (int i = 0; i < MAX; i++) {
                if (t[i].booked == 1) {
                    printf("\nTicket ID: %d\n", i + 1);
                    printf("Name: %s\n", t[i].name);
                    printf("Train: %s\n", t[i].train);
                    printf("Age: %d\n", t[i].age);
                    found = 1;
                }
            }

            if (!found) {
                printf("No tickets booked yet.\n");
            }
        }

        else if (choice ==3) {
            int id;
            printf("\nEnter Ticket ID to cancel: ");
            scanf("%d", &id);

            if (id < 1 || id > MAX || t[id - 1].booked == 0) {
                printf("\nInvalid Ticket ID!\n");
            } else {
                t[id - 1].booked = 0;
                printf("Ticket %d cancelled.\n", id);
            }
        }

        // EXIT
        else if (choice == 4) {
            printf("\nExiting... Thank you!\n");
            break;
        }

        else {
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
