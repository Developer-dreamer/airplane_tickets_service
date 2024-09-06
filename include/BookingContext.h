#pragma once
#include "User.h"

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
    User user_;
    string seat_id_;
    bool is_booked_;
};
