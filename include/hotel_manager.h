#ifndef HOTELMANAGER_H
#define HOTELMANAGER_H

#include <vector>
#include "room.h"
#include "reservation.h"

using namespace std;

class HotelManager {
private:
    vector<Room*> rooms;
    vector<Reservation> reservations;

public:
    void loadRooms();
    void loadReservations();
    void showAvailableRooms();
    void bookRoom();
    void cancelReservation();
    void viewReservations();
    void saveData();

    ~HotelManager();
};

#endif