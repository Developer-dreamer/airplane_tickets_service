#include "RequestFlightInfo.h"

#include <utility>



RequestFlightInfo::RequestFlightInfo(FileProcessor  receiver, string file_name)
    : receiver_(move(receiver)), file_name_(move(file_name))
{};

map<string, string> RequestFlightInfo::getResult() const
{
    return request_result_;
};

void RequestFlightInfo::execute()
{
    
}