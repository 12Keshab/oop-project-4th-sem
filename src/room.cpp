#include "room.h"

Room::Room(int num, double p, bool available) {
    roomNumber = num;
    price = p;
    isAvailable = available;
}

bool Room::getAvailability() {
    return isAvailable;
}

void Room::setAvailability(bool status) {
    isAvailable = status;
}

int Room::getRoomNumber() {
    return roomNumber;
}

Room::~Room() {}

VIPRoom::VIPRoom(int num, double p) : Room(num, p) {}

void VIPRoom::displayDetails() {
    cout << "VIP Room - Room No: "
         << roomNumber
         << " Price: $" << price
         << " Status: "
         << (isAvailable ? "Available" : "Booked")
         << endl;
}

string VIPRoom::getRoomType() {
    return "VIP";
}

MediumRoom::MediumRoom(int num, double p) : Room(num, p) {}

void MediumRoom::displayDetails() {
    cout << "Medium Room - Room No: "
         << roomNumber
         << " Price: $" << price
         << " Status: "
         << (isAvailable ? "Available" : "Booked")
         << endl;
}

string MediumRoom::getRoomType() {
    return "Medium";
}

GeneralRoom::GeneralRoom(int num, double p) : Room(num, p) {}

void GeneralRoom::displayDetails() {
    cout << "General Room - Room No: "
         << roomNumber
         << " Price: $" << price
         << " Status: "
         << (isAvailable ? "Available" : "Booked")
         << endl;
}

string GeneralRoom::getRoomType() {
    return "General";
}