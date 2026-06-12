#include "guest.h"

Guest::Guest() {}

Guest::Guest(string n, string e) {
    name = n;
    email = e;
}

string Guest::getName() {
    return name;
}

string Guest::getEmail() {
    return email;
}