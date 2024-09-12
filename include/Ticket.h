#pragma once
#include <iostream>
#include <map>

using namespace std;
class Ticket {
public:
    Ticket() = default;
    Ticket(int id, string date, string flight, string seat, float price);

    int getId() const;

    map<string, string> obtainTicketInfo() const;

    ~Ticket() = default;
private:
    int id_;
    string date_;
    string flight_number_;
    string seat_id_;
    float price_{};
};