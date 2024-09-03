#include "../include/Flight.h"

Flight::Flight(string flight_id, string departure_airport, string arrival_airport, string departure_time, string arrival_time, string airline, int seats_amount, Seat seats[])
    : flight_id_(std::move(flight_id)),
        departure_airport_(std::move(departure_airport)),
        arrival_airport_(std::move(arrival_airport)),
        departure_time_(std::move(departure_time)),
        arrival_time_(std::move(arrival_time)),
        airline_(std::move(airline)),
        seats_amount_(seats_amount)
{
    // here should be called a reader that
    // will extract all the data about
    // each seat and after this the
    // array with seats will be created
    // and each seat will be correctly initialized
};
