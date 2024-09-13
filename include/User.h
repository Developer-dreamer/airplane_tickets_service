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
    
    [[nodiscard]] float getBalance() const;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] map<string, string> getTicket(int index) const;
    [[nodiscard]] vector<map<string, string>> getTickets() const;
    [[nodiscard]] vector<map<string, string>> getTickets(const string& flight_id) const;
    [[nodiscard]] vector<map<string, string>> getTicketsByFlight(const string& flight_id) const;
    
    void writeOffFunds(float amount);
    void refund(const float& amount);
    
    ~User() = default;
private:
    string full_name_;
    int age_;
    float balance_;
    vector<Ticket> reserved_tickets_;
};