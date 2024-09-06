#pragma once
#include <iostream>
#include <map>

#include "User.h"
#include "Ticket.h"

using namespace std;
class User {
public:
    User();
    explicit User(map<string, string> user_info);
    
    void addTicket(const Ticket& ticket);
    float getBalance() const;
    ~User() = default;
protected:
    string full_name_;
    int age_;
    float balance_;
    Ticket ticket_;
};