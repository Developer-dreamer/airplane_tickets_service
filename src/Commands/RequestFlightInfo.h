#pragma once
#include <iostream>
#include "ICommand.h"
#include "FileProcessor.h"
#include <map>

using namespace std;
class RequestFlightInfo final : public ICommand {
public:
    RequestFlightInfo(FileProcessor receiver, string  file_name);

    void execute() override;

    map<string, string> get_result() const;
private:
    FileProcessor& receiver_;
    const string file_name_;
    map<string, string> request_result_;
};