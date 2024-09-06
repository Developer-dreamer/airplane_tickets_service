#pragma once
#include <iostream>
#include "Seat.h"

using namespace std;

class Seat {
public:
    Seat() = default;
    Seat(string seat_id, int class_id, float price);

    float getPrice() const;

    ~Seat() = default;
private:
    string seat_id_;
    int class_id_;
    float price_;
};
