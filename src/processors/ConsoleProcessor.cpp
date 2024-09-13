#include "ConsoleProcessor.h"

#include <complex>
#include "FileProcessor.h"
#include "BookingContext.h"
#include "src/Commands/BookTicket.h"
#include "src/Commands/RequestFlightInfo.h"
#include "src/Commands/RequestTicketInfo.h"
#include "src/Commands/ReturnTicket.h"

unique_ptr<ICommand> ConsoleProcessor::parseParameters(const shared_ptr<BookingContext>& bookTicket, const string& file_name)
{
    const string options =
            "check <date> <flightNum>"
            "book <flightNum> <place> <userName>"
            "return <ID>"
            "view <ID>"
            "view <UserName>"
            "view <FlightNum>";
    
    cout << "Please enter what action you want to perform: ";
    string command;
    getline(cin, command);

    vector<string> args = validate_command(command);
    
    if(args.empty())
    {
        parseParameters(bookTicket, file_name);
    }
    
    try
    {
        if(args.front() == "check")
        {
            if(args.size() != 3)
            {
                cout << "Not enough arguments" << endl;
            }
            return make_unique<RequestFlightInfo>(args[1], args[2], file_name);
        } if (args.front() == "book")
        {
            if(args.size() != 5)
            {
                cout << "Not enough arguments" << endl;
            }
            return make_unique<BookTicket>(bookTicket, args[1], args[2], args[3], args[4]);
        } if (args.front() == "view")
        {
            if (args.size() == 2)
            {
                return make_unique<RequestTicketInfo>(bookTicket, 0, args[1]);
            } if (args.size() == 3)
            {
                if (args[1] == "username")
                {
                    return make_unique<RequestTicketInfo>(bookTicket, 1, args[2]);
                } if (args[1] == "flight")
                {
                    return make_unique<RequestTicketInfo>(bookTicket, 1, args[2]);
                }
                cout << "Not enough arguments" << endl;
                return nullptr;
            }
        } if (args.front() == "return")
        {
            if(args.size() != 2)
            {
                cout << "Not enough arguments" << endl;
            }
            return make_unique<ReturnTicket>(bookTicket, args[1]);
        }
        cout << "Invalid command" << endl;
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

void ConsoleProcessor::printFileInfo(map<string,string> file_info)
{
    if(file_info.empty())
    {
        cout << "No info found" << endl;
        return;
    }
    
    for (const auto& [key, value] : file_info)
    {
        cout << key << ": " << value << endl;
    }
}

vector<string> ConsoleProcessor::validate_command(const string& command)
{
    vector<string> args;
    vector<string> options = {"check", "book", "return", "view"};
    stringstream ss(command);
    
    string word;
    int arg_count = 0;
    while(ss >> word)
    {
        if(arg_count == 0 && find(options.begin(), options.end(), word) == options.end())
        {
            cout << "Invalid command" << endl;
            return {};
        }
        args.push_back(word);
        word.clear();
        arg_count++;
    }
    return args;
}

