#pragma once
#include <iostream>
#include "ICommand.h"
#include "FileProcessor.h"
#include <map>

using namespace std;
class RequestFlightInfo final : public ICommand {
public:
    explicit RequestFlightInfo(string date, string flight, string file_to_search);

    void execute() override;

    map<string, string> getResult() const;
private:
    FileProcessor receiver_;
    string date_to_search_;
    string flight_to_search_;
    map<string, string> request_result_;
};