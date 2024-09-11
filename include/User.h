#pragma once

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
    int getAge() const;
    
    void writeOffFunds(float amount);
    ~User() = default;
protected:
    string full_name_;
    int age_;
    float balance_;
    vector<Ticket> reserved_tickets_;
};