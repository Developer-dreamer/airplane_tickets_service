#include "ConsoleProcessor.h"

#include <complex>
#include "FileProcessor.h"
#include "BookingContext.h"
#include "src/Commands/BookTicket.h"
#include "src/Commands/RequestFlightInfo.h"
#include "src/Commands/MakePurchase.h"

unique_ptr<ICommand> ConsoleProcessor::parseParameters(const BookingContext& bookTicket)
{
    const string options =
            "1. Show flight: f <flight_id>"
            "2. Buy ticket: b";
    
    cout << "Please enter what action you want to perform: ";
    string option;
    getline(cin, option);

    try
    {
        if (option == "f") {
            const FileProcessor file_processor;
            cout << "Flight info" << endl;
            return make_unique<RequestFlightInfo>(file_processor);
        } if (option == "b") {
            cout << "Buy ticket" << endl;
            return make_unique<MakePurchase>(bookTicket);
        } if (option == "h")
        {
            cout << options << endl;
            parseParameters(bookTicket);
        }
        cout << "Invalid option" << endl;
        return nullptr;
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
        return nullptr;
    }
    
    
}

map<string, string> ConsoleProcessor::authenticateUser()
{
    map <string, string> user;

    cout << "Please enter your username: ";
    getline(cin, user["name"]);

    cout << "Please enter your age: ";
    getline(cin, user["age"]);

    cout << "Please enter your balance (in dollars): ";
    getline(cin, user["balance"]);

    return user;
}

