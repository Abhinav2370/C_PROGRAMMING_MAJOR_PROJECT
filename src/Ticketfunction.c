#include "railway.h"

// Fixed trains list
const char trains[TRAIN_COUNT][30] = {
    "Rajdhani Express",
    "Shatabdi Express",
    "Duronto Express"
};

void init(struct Ticket t[]) {
    for (int i = 0; i < MAX; i++) {
        t[i].booked = 0;
    }
}

void showTrains() {
    printf("\nAvailable Trains:\n");
    for (int i = 0; i < TRAIN_COUNT; i++) {
        printf("%d. %s\n", i + 1, trains[i]);
    }
}

void display(struct Ticket t[]) {
    printf("\n--- Ticket List ---\n");
    for (int i = 0; i < MAX; i++) {
        if (t[i].booked == 1) {
            printf("Seat %d: %s | Train: %s | Age: %d\n",
                   i, t[i].name, t[i].train, t[i].age);
        } else {
            printf("Seat %d: EMPTY\n", i);
        }
    }
}

void book(struct Ticket t[]) {
    int seat = -1;
    for (int i = 0; i < MAX; i++) {
        if (t[i].booked == 0) {
            seat = i;
            break;
        }
    }

    if (seat == -1) {
        printf("\nNo seats available!\n");
        return;
    }

    printf("\nEnter Name: ");
    scanf("%s", t[seat].name);

    showTrains();
    int trainChoice;

    printf("Select Train (1-%d): ", TRAIN_COUNT);
    scanf("%d", &trainChoice);

    if (trainChoice < 1 || trainChoice > TRAIN_COUNT) {
        printf("Invalid train choice!\n");
        return;
    }

    strcpy(t[seat].train, trains[trainChoice - 1]);

    printf("Enter Age: ");
    scanf("%d", &t[seat].age);

    t[seat].booked = 1;

    printf("\nTicket booked! Seat Number: %d\n", seat);
}

void cancel(struct Ticket t[]) {
    int seat;
    printf("\nEnter seat number to cancel: ");
    scanf("%d", &seat);

    if (seat < 0 || seat >= MAX) {
        printf("Invalid seat number!\n");
        return;
    }

    if (t[seat].booked == 0) {
        printf("Seat already empty!\n");
    } else {
        t[seat].booked = 0;
        printf("Ticket cancelled successfully!\n");
    }
}
