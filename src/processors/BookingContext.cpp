#include "BookingContext.h"

void BookingContext::create_purchase() {
    // create PurchaseProcessor
    // execute purchase
    // write ticket to file
}

void BookingContext::book()
{
    
}

void BookingContext::setUser(const User& user)
{
    user_ = user;
}

shared_ptr<User> BookingContext::getUser() const
{
    return make_shared<User>(user_);
}

shared_ptr<Airplane> BookingContext::getFlight(const string& date, const string& flight_d)
{
    for (const auto& airplane : viewed_airplanes_)
    {
        auto flight_info = airplane.getFlightInfo();
        if (flight_info["date"] == date && flight_info["flight_id"] == flight_d)
        {
            return make_shared<Airplane>(airplane);
        }
        throw runtime_error("Flight not found");
    }
}
