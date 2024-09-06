#include <utility>

#include "../include/Ticket.h"

Ticket::Ticket(string  flight, string seat, const float price)
    : flight_number_(move(flight)),
      seat_id_(move(seat)),
      price_(price)
{}




