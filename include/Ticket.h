#pragma once
#include <iostream>
#include <map>

using namespace std;
class Ticket {
public:
    Ticket() = default;
    Ticket(const int& id, string date, string flight, string seat, string passenger, float price);

    [[nodiscard]] int getId() const;

    [[nodiscard]] map<string, string> obtainTicketInfo() const;

    ~Ticket() = default;
private:
    int id_{};
    string date_;
    string flight_number_;
    string seat_id_;
    string passenger_;
    float price_{};
};