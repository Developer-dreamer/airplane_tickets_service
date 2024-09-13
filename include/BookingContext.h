#pragma once
#include <iostream>
#include "User.h"
#include "Airplane.h"

using namespace std;

class BookingContext {
public:
    BookingContext() = default;
    
    void returnTicket(const int& ticket_id);
    [[nodiscard]] map<string, string> viewTicket(const int& id) const;

    void setUser(const User& user);
    
    [[nodiscard]] shared_ptr<User> getUser() const;
    [[nodiscard]] shared_ptr<Airplane> getFlight(const string& date, const string& flight_d) const;
    int updatePurchaseId();
    void addViewedAirplane(const Airplane& airplane);
    
    ~BookingContext() = default;
private:
    int purchase_counter_ = 0;
    vector<shared_ptr<Airplane>> viewed_airplanes_;
    shared_ptr<User> user_;
};
