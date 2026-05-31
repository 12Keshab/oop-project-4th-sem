#include<iostream>
#include<string>
#include <exception>
#include <vector>
#include <fstream>

using namespace std;

// ================= ROOM BASE CLASS =================

class Room {
protected:
    int roomNumber;
    double price;
    bool isAvailable;

public:
    Room(int num, double p, bool available = true) {
        roomNumber = num;
        price = p;
        isAvailable = available;
    }

    virtual void displayDetails() = 0;
    virtual string getRoomType() = 0;

    bool getAvailability() {
        return isAvailable;
    }

    void setAvailability(bool status) {
        isAvailable = status;
    }

    int getRoomNumber() {
        return roomNumber;
    }

    virtual ~Room() {}
};

// ================= DERIVED ROOM CLASSES =================

class VIPRoom : public Room {
public:
    VIPRoom(int num, double p) : Room(num, p) {}

    void displayDetails() override {

        cout << "VIP Room - Room No: "
             << roomNumber
             << " Price: $" << price
             << " Status: "
             << (isAvailable ? "Available" : "Booked")
             << endl;
    }

    string getRoomType() override {
        return "VIP";
    }
};

class MediumRoom : public Room {
public:
    MediumRoom(int num, double p) : Room(num, p) {}

    void displayDetails() override {

        cout << "Medium Room - Room No: "
             << roomNumber
             << " Price: $" << price
             << " Status: "
             << (isAvailable ? "Available" : "Booked")
             << endl;
    }

    string getRoomType() override {
        return "Medium";
    }
};

class GeneralRoom : public Room {
public:
    GeneralRoom(int num, double p) : Room(num, p) {}

    void displayDetails() override {

        cout << "General Room - Room No: "
             << roomNumber
             << " Price: $" << price
             << " Status: "
             << (isAvailable ? "Available" : "Booked")
             << endl;
    }

    string getRoomType() override {
        return "General";
    }
};

// ================= GUEST CLASS =================

class Guest {
private:
    string name;
    string email;

public:
    Guest() {}

    Guest(string n, string e) {
        name = n;
        email = e;
    }

    string getName() {
        return name;
    }

    string getEmail() {
        return email;
    }
};