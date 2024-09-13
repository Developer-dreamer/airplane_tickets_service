#include "RequestFlightInfo.h"

#include <utility>



RequestFlightInfo::RequestFlightInfo(string date, string flight,string file_to_search)
    : receiver_(file_to_search),
    date_to_search_(std::move(date)),
    flight_to_search_(std::move(flight))
{
}

void RequestFlightInfo::execute()
{
    result_ = receiver_.searchFlight(date_to_search_, flight_to_search_);
}

map<string, string> RequestFlightInfo::obtainResults() const
{
    return result_;
}