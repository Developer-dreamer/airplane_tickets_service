#include "BookTicket.h"

BookTicket::BookTicket(const BookingContext& receiver, string date, string flight_num, string place, string user_name)
    : receiver_(receiver),
        user_name(move(user_name)),
        date(move(date)),
        flight_num(move(flight_num)),
        place(move(place))
{}

void BookTicket::execute() {
//     receiver_.bookTicket(date, flight_num, place, user_name);
}