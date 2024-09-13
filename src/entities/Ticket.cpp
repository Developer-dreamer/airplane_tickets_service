#include "../include/Ticket.h"
Ticket::Ticket(const int& id, string date, string  flight, string seat, string passenger, const float price)
    :   id_(id),
      date_(std::move(date)),
      flight_number_(std::move(flight)),
      seat_id_(std::move(seat)),
      passenger_(std::move(passenger)),
      price_(price)
{}


int Ticket::getId() const
{
    return id_;
}

map<string, string> Ticket::obtainTicketInfo() const
{
    map<string, string> ticket_info;
    ticket_info["id"] = to_string(id_);
    ticket_info["passenger"] = passenger_;
    ticket_info["date"] = date_;
    ticket_info["flight_id"] = flight_number_;
    ticket_info["seat_id"] = seat_id_;
    ticket_info["price"] = to_string(price_);
    return ticket_info;
}


