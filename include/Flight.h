#pragma once
#include <iostream>

#include "Seat.h"

using namespace std;

class Flight {
public:
    Flight(
        string flight_id,
        string departure_airport,
        string arrival_airport,
        string departure_time,
        string arrival_time,
        string airline,
        int seats_amount,
        Seat seats[]);
    
private:
    string flight_id_;
    string departure_airport_;
    string arrival_airport_;
    string departure_time_;
    string arrival_time_;
    string airline_;
    int seats_amount_;
    Seat seats_[];
};