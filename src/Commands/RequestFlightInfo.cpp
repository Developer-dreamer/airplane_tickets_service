#include "RequestFlightInfo.h"



RequestFlightInfo::RequestFlightInfo(FileProcessor receiver, string file_name)
    : receiver_(receiver), file_name_(std::move(file_name))
{
    
}

map<string, string> RequestFlightInfo::get_result() const
{
    return request_result_;
};

void RequestFlightInfo::execute()
{
    return;
}