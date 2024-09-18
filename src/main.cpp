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
    
    auto book_ticket = make_shared<BookingContext>();
    
    FileProcessor file_processor(file_path);
    auto config_data = file_processor.readFile();

    for(const auto& flight_info : config_data)
    {
        Airplane airplane(flight_info);
        book_ticket->addViewedAirplane(airplane);
    }
    

    // initialize User session
    const User user(ConsoleProcessor::authenticateUser());
    book_ticket->setUser(user);
    
    while (true)
    {
        unique_ptr<ICommand> command = ConsoleProcessor::parseParameters(book_ticket);
        if (command == nullptr) {
            break;
        }
        
        command->execute();
        
        if(const auto getAvailableSeats = dynamic_cast<RequestFlightInfo*>(command.get()))
        {
            ConsoleProcessor::printInfo(getAvailableSeats->obtainResults());
        } if (const auto requestTicketInfoCommand = dynamic_cast<RequestTicketInfo*>(command.get()))
        {
            const auto result = requestTicketInfoCommand->obtainResults();
            if (requestTicketInfoCommand->view_type == 0)
            {
                ConsoleProcessor::printInfo(result[0]);
            } else
            {
                for (const auto& map : result)
                {
                    ConsoleProcessor::printInfo(map);
                }
            }
        }
    }

    return 0;
}