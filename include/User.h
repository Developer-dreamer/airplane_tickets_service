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
    void removeTicket(const int& ticket_id);
    
    float getBalance() const;
    int getAge() const;
    map<string, string> getTicket(const int& id) const;
    vector<map<string, string>> getTickets(const string& flight_id) const;
    vector<map<string, string>> getTicketsByFlight(const string& flight_id) const;
    
    void writeOffFunds(float amount);
    void refund(const float& amount);
    
    ~User() = default;
private:
    string full_name_;
    int age_;
    float balance_;
    vector<Ticket> reserved_tickets_;
};