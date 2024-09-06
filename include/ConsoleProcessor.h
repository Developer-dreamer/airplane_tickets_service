#pragma once
#include <iostream>
#include <map>
#include "BookingContext.h"
#include "ICommand.h"

using namespace std;

class ICommand;

class ConsoleProcessor {
public:
    static unique_ptr<ICommand> parseParameters(const BookingContext& bookTicket);
    static void printJsonMap();
    
    ~ConsoleProcessor() = default;
};
