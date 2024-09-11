#pragma once
#include "User.h"
#include "Airplane.cpp"

class BookingContext {
public:
    BookingContext();
    
    void create_purchase();
    
    void book();
    void change_seat();

    void setUser(const User& user);
    User getUser() const;
    string getSeat() const;
    
    ~BookingContext() = default;
private:
    Airplane airplane_;
    User user_;
    string seat_id_;
    bool is_booked_;
};
