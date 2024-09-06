#pragma once
#include <iostream>
#include "User.h"
#include "Ticket.h"

using namespace std;
class User {
public:
    User();
    User(string  full_name, const int& age, const float& balance);
    
    void addTicket(const Ticket& ticket);
    float getBalance() const;
    ~User() = default;
protected:
    string full_name_;
    int age_;
    float balance_;
    Ticket ticket_;
};