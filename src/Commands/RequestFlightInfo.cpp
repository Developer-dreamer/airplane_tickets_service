#include "RequestFlightInfo.h"

#include <utility>



RequestFlightInfo::RequestFlightInfo(FileProcessor  receiver)
    : receiver_(move(receiver))
{};

map<string, string> RequestFlightInfo::getResult() const
{
    return request_result_;
};

void RequestFlightInfo::execute()
{
    
}