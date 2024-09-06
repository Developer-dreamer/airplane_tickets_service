#include "ConsoleProcessor.h"

#include <complex>
#include "FileProcessor.h"
#include "BookingContext.h"
#include "src/Commands/RequestFlightInfo.h"
#include "src/Commands/MakePurchase.h"

unique_ptr<ICommand> ConsoleProcessor::parseParameters(const BookingContext& bookTicket)
{
    const string options = "1. Show flights: all"
            "2. Show flight: f <flight_id>"
            "3. Show seat: s <flight_id> <seat_id>"
            "4. Buy ticket: b"
            "5 Show ticket: t";
    
    cout << "Please enter what action you want to perform: ";
    vector<string> args;

    const auto input = new char[20];
    cin.getline(input, 100);

    string temp;
    for (int i = 0; i < 20; i++)
    {
        if (input[i] == ' ')
        {
            args.push_back(temp);
            temp = "";
        }
        else if (input[i] == '\0')
        {
            args.push_back(temp);
            break;
        }
        else
        {
            temp += input[i];
        }
    }

    const string option =  args[0];
    const string file_name = args[1];
    delete [] input;
    try
    {
        const FileProcessor file_processor;
        if (option == "all") {
            cout << "All flights" << endl;
            return make_unique<RequestFlightInfo>(file_processor, file_name);
        } if (option == "f") {
            cout << "Flight info" << endl;
            return make_unique<RequestFlightInfo>(file_processor, file_name);
        } if (option == "s") {
            cout << "Seat info" << endl;
            return make_unique<RequestFlightInfo>(file_processor, file_name);
        } if (option == "b") {
            cout << "Buy ticket" << endl;
            return make_unique<MakePurchase>(bookTicket);
        } if (option == "t") {
            cout << "Ticket info" << endl;
            return make_unique<RequestFlightInfo>(file_processor, file_name);
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

