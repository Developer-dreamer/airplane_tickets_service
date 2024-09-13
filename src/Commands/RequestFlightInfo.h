#pragma once
#include <iostream>
#include "ICommand.h"
#include <map>

#include "BookingContext.h"

using namespace std;
class RequestFlightInfo final : public ICommand{
public:
    RequestFlightInfo(shared_ptr<BookingContext> booking, string date_to_search, string flight_to_search);

    void execute() override;

    map<string, float> obtainResults() const;
private:
    shared_ptr<BookingContext> receiver_;
    string date_to_search_;
    string flight_to_search_;
    map<string, float> result_;
};