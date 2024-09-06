#pragma once
#include <iostream>
#include <utility>
#include "src/entities/Flight.cpp"
#include "Seat.h"

using namespace std;
class Ticket {
public:
    Ticket() = default;
    Ticket(const Flight& flight, const Seat& seat);

    void add_food();
    void add_drink();
    void add_extra_baggage();
    void add_priority_boarding();
    void add_insurance();
    void add_pets_transportation();

    void change_price();

    ~Ticket() = default;
private:
    Flight flight_;
    Seat seat_;
    float price_{};
};