#include "RequestFlightInfo.h"

#include <utility>



RequestFlightInfo::RequestFlightInfo(shared_ptr<BookingContext> booking, string date_to_search, string flight_to_search)
    : receiver_(booking), date_to_search_(move(date_to_search)), flight_to_search_(move(flight_to_search))
{
}

void RequestFlightInfo::execute()
{
    const auto flight = receiver_->getFlight(date_to_search_, flight_to_search_);
    result_ = flight->getAllAvailableSeats();
}

map<string, float> RequestFlightInfo::obtainResults() const
{
    return result_;
}