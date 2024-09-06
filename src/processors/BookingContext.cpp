#include "BookingContext.h"


BookingContext::BookingContext()
    : seat_id_(),
      is_booked_(false)
{}

void BookingContext::create_purchase() {
    // create PurchaseProcessor
    // execute purchase
    // write ticket to file
}

void BookingContext::setUser(const User& user)
{
    user_ = user;
}

User BookingContext::getUser() const
{
    return user_;
}

string BookingContext::getSeat() const
{
    return seat_id_;
}
