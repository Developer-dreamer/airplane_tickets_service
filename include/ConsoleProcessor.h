#pragma once
#include <iostream>
#include <map>
#include "BookingContext.h"
#include "ICommand.h"

using namespace std;

class ICommand;

class ConsoleProcessor {
public:
    static unique_ptr<ICommand> parseParameters(const BookingContext& bookTicket, const string& file_name);
    static map<string,string> authenticateUser();
    static void printFileInfo(map<string, string> file_info);
    
    ~ConsoleProcessor() = default;
private:
    static vector<string> validate_command(const string& command);
};
