#include <iostream>

#include "BookingContext.h"
#include "ConsoleProcessor.h"
#include "FileProcessor.h"
#include "ICommand.h"
#include "PurchaseProcessor.h"
#include "Commands/BookTicket.h"
#include "Commands/RequestFlightInfo.h"
using namespace std;

int main() {
    // define files directory storage:
    const string file_path = "../src/data_files/flights.txt";
    
    // initializing Main Processors:
    BookingContext book_ticket;

    // //initialize user session
    const User user(ConsoleProcessor::authenticateUser());
    book_ticket.setUser(user);

    
    while (true) {
        unique_ptr<ICommand> command = ConsoleProcessor::parseParameters(book_ticket, file_path);
        if (command == nullptr) {
            throw invalid_argument("Invalid command");
        }
        
        command->execute();
        
        if(const auto fileProcessCommand = dynamic_cast<RequestFlightInfo*>(command.get()))
        {
            const map<string, string> result = fileProcessCommand->getResult();
            ConsoleProcessor::printFileInfo(result);
        }
    }

    // Process request, by defining either user  wants to see timetable or concrete plane or available seats only
        // print available ticket
    
    // If the user wants to  make a purchase, then define the user and the seat, then call the purchase method
        // here we are checking whether user is student
    
    // create a ticket instance, set parameters and assign to the user object
    
    return 0;
}