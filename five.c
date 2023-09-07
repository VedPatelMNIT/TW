#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Train {
    int trainNumber;
    char trainName[50];
    int totalSeats;
    int availableSeats;
    float fare;
};

struct Reservation {
    int reservationNumber;
    int trainNumber;
    char passengerName[50];
    int age;
    char gender;
};

void displayMenu();
void displayTrains(struct Train trains[], int numTrains);
void bookTicket(struct Train trains[], int numTrains, struct Reservation reservations[], int* numReservations);
void displayReservations(struct Reservation reservations[], int numReservations);

int main() {
    struct Train trains[5]; // Assuming there are 5 trains
    struct Reservation reservations[50]; // Assuming a maximum of 50 reservations
    int numTrains = 0;
    int numReservations = 0;

    // Initialize train data (you can add more trains)
    trains[numTrains++] = (struct Train){1, "Train A", 100, 100, 500.0};
    trains[numTrains++] = (struct Train){2, "Train B", 120, 120, 600.0};

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayTrains(trains, numTrains);
                break;
            case 2:
                bookTicket(trains, numTrains, reservations, &numReservations);
                break;
            case 3:
                displayReservations(reservations, numReservations);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    printf("\nRailway Reservation System\n");
    printf("1. Display Available Trains\n");
    printf("2. Book a Ticket\n");
    printf("3. Display Reservations\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void displayTrains(struct Train trains[], int numTrains) {
    printf("\nAvailable Trains:\n");
    printf("Train No.\tTrain Name\tTotal Seats\tAvailable Seats\tFare\n");
    for (int i = 0; i < numTrains; i++) {
        printf("%d\t\t%s\t\t%d\t\t%d\t\t%.2f\n", trains[i].trainNumber, trains[i].trainName, trains[i].totalSeats, trains[i].availableSeats, trains[i].fare);
    }
}

void bookTicket(struct Train trains[], int numTrains, struct Reservation reservations[], int* numReservations) {
    int trainNumber;
    int availableSeats;
    int reservationNumber;

    // Display available trains
    displayTrains(trains, numTrains);

    // Ask the user to select a train
    printf("Enter the Train Number to book a ticket: ");
    scanf("%d", &trainNumber);

    // Find the selected train
    int trainIndex = -1;
    for (int i = 0; i < numTrains; i++) {
        if (trains[i].trainNumber == trainNumber) {
            trainIndex = i;
            break;
        }
    }

    if (trainIndex == -1) {
        printf("Invalid Train Number. Please try again.\n");
        return;
    }

    // Check seat availability
    availableSeats = trains[trainIndex].availableSeats;
    if (availableSeats <= 0) {
        printf("Sorry, there are no available seats on this train.\n");
        return;
    }

    // Get passenger details
    struct Reservation newReservation;
    newReservation.trainNumber = trainNumber;

    printf("Enter Passenger Name: ");
    scanf("%s", newReservation.passengerName);

    printf("Enter Passenger Age: ");
    scanf("%d", &newReservation.age);

    printf("Enter Passenger Gender (M/F): ");
    scanf(" %c", &newReservation.gender);

    // Assign a reservation number (You can implement your own logic for this)
    reservationNumber = (*numReservations) + 1;
    newReservation.reservationNumber = reservationNumber;

    // Update the reservation and train information
    reservations[(*numReservations)++] = newReservation;
    trains[trainIndex].availableSeats--;

    printf("Ticket booked successfully!\n");
    printf("Reservation Number: %d\n", reservationNumber);
    printf("Train Name: %s\n", trains[trainIndex].trainName);
    printf("Passenger Name: %s\n", newReservation.passengerName);
    printf("Age: %d\n", newReservation.age);
    printf("Gender: %c\n", newReservation.gender);
}


void displayReservations(struct Reservation reservations[], int numReservations) {
    printf("\nReservations:\n");
    printf("Reservation No.\tTrain No.\tPassenger Name\tAge\tGender\n");
    for (int i = 0; i < numReservations; i++) {
        printf("%d\t\t%d\t\t%s\t\t%d\t%c\n", reservations[i].reservationNumber, reservations[i].trainNumber, reservations[i].passengerName, reservations[i].age, reservations[i].gender);
    }
}
