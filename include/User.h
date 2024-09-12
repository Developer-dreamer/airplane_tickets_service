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
    map<string, string> getTicket(int index) const;
    
    void writeOffFunds(float amount);
    
    ~User() = default;
private:
    string full_name_;
    int age_;
    float balance_;
    vector<Ticket> reserved_tickets_;
};