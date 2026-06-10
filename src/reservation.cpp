#include "reservation.h"
#include <iostream>

using namespace std;

// Constructor
Reservation::Reservation(int id, Guest g, int room,
                         string checkin, string checkout) {
    reservationID = id;
    guest = g;
    roomNumber = room;
    checkInDate = checkin;
    checkOutDate = checkout;
}

// Get Reservation ID
int Reservation::getReservationID() {
    return reservationID;
}

// Get Room Number
int Reservation::getRoomNumber() {
    return roomNumber;
}

// Display Reservation Details
void Reservation::displayReservation() {
    cout << "\nReservation ID: " << reservationID << endl;
    cout << "Guest Name: " << guest.getName() << endl;
    cout << "Guest Email: " << guest.getEmail() << endl;
    cout << "Room Number: " << roomNumber << endl;
    cout << "Check In Date: " << checkInDate << endl;
    cout << "Check Out Date: " << checkOutDate << endl;
}

// Save Reservation in File Format
string Reservation::fileFormat() {
    return to_string(reservationID) + "," +
           guest.getName() + "," +
           guest.getEmail() + "," +
           to_string(roomNumber) + "," +
           checkInDate + "," +
           checkOutDate;
}