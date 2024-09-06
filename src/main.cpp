#include <iostream>

#include "BookingContext.h"
#include "ConsoleProcessor.h"
#include "FileProcessor.h"
#include "ICommand.h"
#include "PurchaseProcessor.h"
#include "Commands/BookTicket.h"
using namespace std;

int main() {
    // initializing Main Processors:
    BookingContext book_ticket;
    
    const User user(ConsoleProcessor::authenticateUser());
    book_ticket.setUser(user);

    unique_ptr<ICommand> command = ConsoleProcessor::parseParameters(book_ticket);

    if (command == nullptr) {
        ;
    }
    // if (dynamic_cast<RequestFlightInfo*>(command))
    // {
    //     
    // }
    //
    // delete command;
    // while (true) {
    //     ICommand* command = ConsoleProcessor::parseParameters();
    //     if (command == nullptr) {
    //         break;
    //     }
    //     command->execute(book_ticket);
    //     delete command;
    // }
    
    
    // Parse request

    // Process request, by defining either user  wants to see timetable or concrete plane or available seats only
        // print available ticket
    
    // If the user wants to  make a purchase, then define the user and the seat, then call the purchase method
        // here we are checking whether user is student
    
    // create a ticket instance, set parameters and assign to the user object
    
    return 0;
}