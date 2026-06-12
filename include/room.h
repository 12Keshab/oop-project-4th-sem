#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
using namespace std;

class Room {
protected:
    int roomNumber;
    double price;
    bool isAvailable;

public:
    Room(int num, double p, bool available = true);

    virtual void displayDetails() = 0;
    virtual string getRoomType() = 0;

    bool getAvailability();
    void setAvailability(bool status);
    int getRoomNumber();

    virtual ~Room();
};

class VIPRoom : public Room {
public:
    VIPRoom(int num, double p);
    void displayDetails() override;
    string getRoomType() override;
};

class MediumRoom : public Room {
public:
    MediumRoom(int num, double p);
    void displayDetails() override;
    string getRoomType() override;
};

class GeneralRoom : public Room {
public:
    GeneralRoom(int num, double p);
    void displayDetails() override;
    string getRoomType() override;
};

#endif