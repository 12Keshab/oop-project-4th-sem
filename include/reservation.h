#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>
#include "Guest.h"

using namespace std;

class Reservation {
private:
    int reservationID;
    Guest guest;
    int roomNumber;
    string checkInDate;
    string checkOutDate;

public:
    Reservation(
        int id,
        Guest g,
        int room,
        string checkin,
        string checkout
    );

    int getReservationID();
    int getRoomNumber();

    void displayReservation();
    string fileFormat();
};

#endif