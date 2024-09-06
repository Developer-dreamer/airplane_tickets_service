#include "../include/Seat.h"

Seat::Seat(string seat_id, int class_id, float price)
    : seat_id_(std::move(seat_id)),
        class_id_(class_id),
        price_(price)
{}

float Seat::getPrice() const
{
    return price_;
};
