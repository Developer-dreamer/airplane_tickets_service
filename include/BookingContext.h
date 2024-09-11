#pragma once
#include <iostream>
#include "User.h"
#include "Airplane.h"

using namespace std;

class BookingContext {
public:
    BookingContext() = default;
    
    void change_seat();

    void setUser(const User& user);
    
    shared_ptr<User> getUser() const;
    shared_ptr<Airplane> getFlight(const string& date, const string& flight_d) const;
  
    
    ~BookingContext() = default;
private:
    vector<Airplane> viewed_airplanes_;
    User user_;
};
