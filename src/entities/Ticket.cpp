#include <utility>

#include "../include/Ticket.h"

Ticket::Ticket(string date, string  flight, string seat, const float price)
    : date_(move(date)),
      flight_number_(move(flight)),
      seat_id_(move(seat)),
      price_(price)
{}




