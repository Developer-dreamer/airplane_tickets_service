#pragma once
#include <iostream>
#include "ICommand.h"
#include "FileProcessor.h"
#include <map>

using namespace std;
class RequestFlightInfo final : public ICommand {
public:
    explicit RequestFlightInfo(FileProcessor  receiver);

    void execute() override;

    map<string, string> getResult() const;
private:
    FileProcessor receiver_;
    map<string, string> request_result_;
};