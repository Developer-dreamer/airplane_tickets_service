#pragma once
#include <iostream>
#include "User.h"
#include "Ticket.h"
#include "Seat.h"

using namespace std;
class User {
public:
    User(string  full_name, const int& age, const float& balance);
    
    Ticket Purchase(const Seat* seat);

    ~User() = default;
protected:
    string full_name_;
    int age_;
    float balance_;
    Ticket* ticket_{};
};