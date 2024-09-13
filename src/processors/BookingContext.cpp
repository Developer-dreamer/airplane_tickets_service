#include "BookingContext.h"

void BookingContext::setUser(const User& user)
{
    user_ = make_shared<User>(user);
}

shared_ptr<User> BookingContext::getUser() const
{
    return user_;
}

shared_ptr<Airplane> BookingContext::getFlight(const string& date, const string& flight_d) const
{
    for (const auto& airplane : viewed_airplanes_)
    {
        auto flight_info = airplane->getFlightInfo();
        if (flight_info["date"] == date && flight_info["flight_id"] == flight_d)
        {
            return airplane;
        }
        throw runtime_error("Flight not found");
    }
    return make_shared<Airplane>();
}

int BookingContext::updatePurchaseId()
{
    return ++purchase_counter_;
}

void BookingContext::addViewedAirplane(const Airplane& airplane)
{
    viewed_airplanes_.push_back(make_shared<Airplane>(airplane));
}

void BookingContext::returnTicket(const int& id)
{
    auto ticket = user_->getTicket(id);
    try
    {
        for (auto& airplane : viewed_airplanes_)
        {
            if (airplane->getFlightInfo()["flight_id"] == ticket["flight_id"])
            {
                airplane->CancelSeat(ticket["seat_id"]);
            }
        }
    } catch (exception& e) {
        cout << e.what() << endl;
        return;
    }
    user_->removeTicket(id);
    user_->refund(stof(ticket["price"]));
}

map<string, string> BookingContext::viewTicket(const int& id) const
{
    const map<string, string> ticket = user_->getTicket(id);
    return ticket;
}

