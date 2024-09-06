#pragma once
#include <iostream>
#include <utility>

using namespace std;
class Ticket {
public:
    Ticket() = default;
    Ticket(string flight, string seat, float price);

    void add_food();
    void add_drink();
    void add_extra_baggage();
    void add_priority_boarding();
    void add_insurance();
    void add_pets_transportation();

    void change_price();

    ~Ticket() = default;
private:
    string flight_number_;
    string seat_id_;
    float price_{};
};