#include "../include/Ticket.h"

Ticket::Ticket(const Flight& flight, const Seat& seat)
    : flight_(flight), seat_(seat)
{
    price_ = seat.get_price();
}


