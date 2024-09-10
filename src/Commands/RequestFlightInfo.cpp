#include "RequestFlightInfo.h"

#include <utility>



RequestFlightInfo::RequestFlightInfo(string date, string flight,string file_to_search)
    : receiver_(file_to_search),
    date_to_search_(move(date)),
    flight_to_search_(move(flight))
{
}

map<string, string> RequestFlightInfo::getResult() const
{
    return request_result_;
};

void RequestFlightInfo::execute()
{
    request_result_ = receiver_.searchFlight(date_to_search_, flight_to_search_);
}
