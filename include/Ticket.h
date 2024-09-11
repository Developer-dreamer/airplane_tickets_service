#pragma once
#include <iostream>
#include <utility>

using namespace std;
class Ticket {
public:
    Ticket() = default;
    Ticket(string date, string flight, string seat, float price);

    void change_price();

    ~Ticket() = default;
private:
    string date_;
    string flight_number_;
    string seat_id_;
    float price_{};
};