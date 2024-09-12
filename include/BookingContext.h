#pragma once
#include <iostream>
#include "User.h"
#include "Airplane.h"

using namespace std;

class BookingContext {
public:
    BookingContext() = default;
    
    void returnTicket() const;
    map<string, string> viewTicket(const int& id) const;
    map<string, string> viewByAirplane(const string& flight_id) const;
    map<string,string> viewByUser(const string& user_name) const;

    void setUser(const User& user);
    
    shared_ptr<User> getUser() const;
    shared_ptr<Airplane> getFlight(const string& date, const string& flight_d) const;
    int updatePurchaseId();
    void addViewedAirplane(const Airplane& airplane);
    
    ~BookingContext() = default;
private:
    int purchase_counter_ = 0;
    vector<Airplane> viewed_airplanes_;
    User user_;
};
