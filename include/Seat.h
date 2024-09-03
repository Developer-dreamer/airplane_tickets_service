#pragma once
#include <iostream>
#include <utility>
#include "User.h"
#include "Ticket.h"
#include "Seat.h"

using namespace std;

class Seat {
public:
    Seat(string seat_id, int class_id, float price);

    float get_price() const;

    ~Seat() = default;
private:
    string seat_id_;
    int class_id_;
    float price_;
};
