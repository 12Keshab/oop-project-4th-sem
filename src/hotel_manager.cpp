#include "hotel_manager.h"
#include "exception.h"

#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;


// ================= LOAD ROOMS =================

void HotelManager::loadRooms() {

    rooms.push_back(new GeneralRoom(101, 40));
    rooms.push_back(new GeneralRoom(102, 45));

    rooms.push_back(new MediumRoom(201, 70));
    rooms.push_back(new MediumRoom(202, 80));

    rooms.push_back(new VIPRoom(301, 150));
}

// ================= LOAD RESERVATIONS =================

void HotelManager::loadReservations() {

    ifstream file("reservations.txt");

    if (!file) {
        return;
    }

    string line;

    while (getline(file, line)) {

        string data[6];
        string temp = "";
        int index = 0;

        for (char ch : line) {

            if (ch == ',') {
                data[index++] = temp;
                temp = "";
            }
            else {
                temp += ch;
            }
        }

        data[index] = temp;

        int reservationID = stoi(data[0]);
        string name = data[1];
        string email = data[2];
        int roomNumber = stoi(data[3]);
        string checkIn = data[4];
        string checkOut = data[5];

        Guest guest(name, email);

        Reservation reservation(
            reservationID,
            guest,
            roomNumber,
            checkIn,
            checkOut
        );

        reservations.push_back(reservation);

        // Mark room as unavailable
        for (Room* room : rooms) {
            if (room->getRoomNumber() == roomNumber) {
                room->setAvailability(false);
            }
        }
    }

    file.close();
}

// ================= SHOW AVAILABLE ROOMS =================

void HotelManager::showAvailableRooms() {

    cout << "\n===== AVAILABLE ROOMS =====\n";

    bool found = false;

    for (Room* room : rooms) {

        if (room->getAvailability()) {

            room->displayDetails();
            found = true;
        }
    }

    if (!found) {
        cout << "No rooms available.\n";
    }
}

// ================= BOOK ROOM =================

bool isPastDate(string date)
{
    if (date.length() != 10)
        return true;

    if (date[4] != '-' || date[7] != '-')
        return true;

    try
    {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));

        if (month < 1 || month > 12)
            return true;

        int maxDays;

        switch(month)
        {
            case 2:
                maxDays = 29;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                maxDays = 30;
                break;
            default:
                maxDays = 31;
        }

        if(day < 1 || day > maxDays)
            return true;

        time_t now = time(0);
        tm* current = localtime(&now);

        int currentYear = current->tm_year + 1900;
        int currentMonth = current->tm_mon + 1;
        int currentDay = current->tm_mday;

        if(year < currentYear)
            return true;

        if(year == currentYear && month < currentMonth)
            return true;

        if(year == currentYear &&
           month == currentMonth &&
           day < currentDay)
            return true;

        return false;
    }
    catch(...)
    {
        return true;
    }
}
void HotelManager::bookRoom() {


    int roomNumber;
    string name;
    string email;
    string checkIn;
    string checkOut;

    cout << "\nEnter Room Number: ";

    if (!(cin >> roomNumber)) {

        cin.clear();
        cin.ignore(1000, '\n');

        throw InvalidInputException();
    }

    cin.ignore(1000, '\n');

    cout << "Enter Guest Name: ";
    getline(cin, name);

    cout << "Enter Guest Email: ";
    getline(cin, email);

    cout << "Enter Check In Date (YYYY-MM-DD): ";
    getline(cin, checkIn);

    cout << "Enter Check Out Date (YYYY-MM-DD): ";
    getline(cin, checkOut);

    //Check check-in 
    if (isPastDate(checkIn)) {

        cout << "\nInvalid date or check-in date is in the past!\n";
        cout << "Please use YYYY-MM-DD format.\n";
        return;
    }

    // Check if check-out is after check-in
    if (checkOut <= checkIn) {

        cout << "\nCheck-out date must be after check-in date!\n";
        cout << "Please use YYYY-MM-DD format.\n";
        return;
    }

    try {

        for (Room* room : rooms) {

            if (room->getRoomNumber() == roomNumber) {

                if (!room->getAvailability()) {
                    throw RoomNotAvailableException();
                }

                room->setAvailability(false);

                Guest guest(name, email);

                int reservationID = reservations.size() + 1001;

                Reservation newReservation(
                    reservationID,
                    guest,
                    roomNumber,
                    checkIn,
                    checkOut
                );

                reservations.push_back(newReservation);

                saveData();

                cout << "\nRoom booked successfully!\n";
                cout << "Reservation ID: "
                     << reservationID
                     << endl;

                return;
            }
        }

        cout << "\nRoom not found!\n";
    }

    catch (RoomNotAvailableException& e) {

        cout << "\n"
             << e.what()
             << endl;
    }
}

// ================= CANCEL RESERVATION =================

void HotelManager::cancelReservation() {

    int reservationID;

    cout << "\nEnter Reservation ID to cancel: ";

    if (!(cin >> reservationID)) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw InvalidInputException();
    }

    for (int i = 0; i < reservations.size(); i++) {

        if (reservations[i].getReservationID() == reservationID) {

            int roomNum = reservations[i].getRoomNumber();

            // Make room available again
            for (Room* room : rooms) {

                if (room->getRoomNumber() == roomNum) {

                    room->setAvailability(true);
                    break;
                }
            }

            reservations.erase(reservations.begin() + i);

            saveData();

            cout << "\nReservation cancelled successfully!\n";

            return;
        }
    }

    cout << "\nReservation not found!\n";
}

// ================= VIEW RESERVATIONS =================

void HotelManager::viewReservations() {

    cout << "\n===== RESERVATIONS =====\n";

    if (reservations.empty()) {

        cout << "No reservations found!\n";
    }
    else {

        for (Reservation& r : reservations) {
            r.displayReservation();
        }
    }
}

// ================= SAVE DATA =================

void HotelManager::saveData() {

    ofstream file("reservations.txt");

    for (Reservation& r : reservations) {
        file << r.fileFormat() << endl;
    }

    file.close();
}

// ================= DESTRUCTOR =================

HotelManager::~HotelManager() {

    for (Room* room : rooms) {
        delete room;
    }
}