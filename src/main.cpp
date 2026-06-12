#include <iostream>
#include "hotel_manager.h"
#include "exception.h"

using namespace std;

int main() {

    HotelManager hotel;

    hotel.loadRooms();
    hotel.loadReservations();

    int choice;

    do {

        cout << "\n===== HOTEL RESERVATION SYSTEM =====\n";
        cout << "1. View Available Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. View Reservations\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nInvalid input! Enter numbers only.\n";
            continue;
        }

        try {

            switch (choice) {

            case 1:
                hotel.showAvailableRooms();
                break;

            case 2:
                hotel.bookRoom();
                break;

            case 3:
                hotel.cancelReservation();
                break;

            case 4:
                hotel.viewReservations();
                break;

            case 5:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
            }

        } catch (InvalidInputException& e) {
            cout << e.what() << endl;
        }

    } while (choice != 5);

    return 0;
}