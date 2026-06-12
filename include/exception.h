#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
using namespace std;

class RoomNotAvailableException : public exception {
public:
    const char* what() const noexcept override {
        return "Room is not available!";
    }
};

class InvalidInputException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid input entered!";
    }
};

#endif