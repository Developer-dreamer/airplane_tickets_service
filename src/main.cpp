#include <iostream>

#include "BookingContext.h"
#include "ConsoleProcessor.h"
#include "FileProcessor.h"
#include "ICommand.h"
#include "PurchaseProcessor.h"
#include "Commands/RequestFlightInfo.h"
#include "Commands/RequestTicketInfo.h"
using namespace std;

int main() {
    // define files directory storage:
    const string file_path = "../src/data_files/flights.txt";
    
    // initializing Main Processors:
    auto book_ticket = make_shared<BookingContext>();

    // initialize User session
    
    const User user(ConsoleProcessor::authenticateUser());
    book_ticket->setUser(user);

    
    while (true)
    {
        unique_ptr<ICommand> command = ConsoleProcessor::parseParameters(book_ticket, file_path);
        if (command == nullptr) {
            throw invalid_argument("Invalid command");
        }
        
        command->execute();
        
        if(const auto fileProcessCommand = dynamic_cast<RequestFlightInfo*>(command.get()))
        {
            const map<string, string> result = fileProcessCommand->obtainResults();
            Airplane airplane(result);
            book_ticket->addViewedAirplane(airplane);
            ConsoleProcessor::printFileInfo(result);
        } if (const auto requestTicketInfoCommand = dynamic_cast<RequestTicketInfo*>(command.get()))
        {
            const auto result = requestTicketInfoCommand->obtainResults();
        }
    }

    // Process request, by defining either user  wants to see timetable or concrete plane or available seats only
        // print available ticket
    
    // If the user wants to  make a purchase, then define the user and the seat, then call the purchase method
        // here we are checking whether user is student
    
    // create a ticket instance, set parameters and assign to the user object
    
    return 0;
}