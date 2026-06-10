#ifndef GUEST_H
#define GUEST_H

#include <string>
using namespace std;

class Guest {
private:
    string name;
    string email;

public:
    Guest();
    Guest(string n, string e);

    string getName();
    string getEmail();
};

#endif