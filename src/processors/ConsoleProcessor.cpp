#include "ConsoleProcessor.h"

#include <complex>
#include "FileProcessor.h"
#include "BookingContext.h"
#include "src/Commands/BookTicket.h"
#include "src/Commands/RequestFlightInfo.h"
#include "src/Commands/RequestTicketInfo.h"
#include "src/Commands/ReturnTicket.h"

int ConsoleProcessor::recursive_counter_ = 0;

unique_ptr<ICommand> ConsoleProcessor::parseParameters(const shared_ptr<BookingContext>& bookTicket)
{
    if (recursive_counter_ > 3) {
        cout << "Too many attempts" << endl;
        return nullptr;
    }
    
    const string options =
            "check <date> <flightNum>"
            "book <flightNum> <place> <userName>"
            "return <ID>"
            "view <ID>"
            "view <UserName>"
            "view <FlightNum>";
    
    cout << "Please enter what action you want to perform: ";
    string command;
    getline_wrapper(cin, command);

    vector<string> args = validate_command(command);

    if (args.front() == "exit")
    {
        return nullptr;
    } if(args.empty())
    {
        recursive_counter_++;
        parseParameters(bookTicket);
    }

    if(args.front() == "check")
    {
        if(args.size() != 3)
        {
            cout << "Wrong number of arguments" << endl;
            recursive_counter_++;
            parseParameters(bookTicket);
        }
        recursive_counter_ = 0;
        return make_unique<RequestFlightInfo>(bookTicket, args[1], args[2]);
    } if (args.front() == "book")
    {
        if(args.size() != 5)
        {
            cout << "Wrong number of arguments" << endl;
            recursive_counter_++;
            parseParameters(bookTicket);
        }
        recursive_counter_ = 0;
        return make_unique<BookTicket>(bookTicket, args[1], args[2], args[3], args[4]);
    } if (args.front() == "view")
    {
        if (args.size() == 2)
        {
            string id = args[1];
            while (true)
            {
                try
                {
                    stoi(id);
                    break;
                } catch (invalid_argument& e) {
                    cout << "Enter an integer parameter that represents ID" << endl;
                    getline(cin, id);
                }
            }
            recursive_counter_ = 0;
            return make_unique<RequestTicketInfo>(bookTicket, 0, args[1]);
        } if (args.size() == 3)
        {
            if (args[1] == "username")
            {
                recursive_counter_ = 0;
                return make_unique<RequestTicketInfo>(bookTicket, 1, args[2]);
            } if (args[1] == "flight")
            {
                recursive_counter_ = 0;
                return make_unique<RequestTicketInfo>(bookTicket, 1, args[2]);
            }
        } else
        {
            cout << "Wrong number of arguments" << endl;
            recursive_counter_++;
            parseParameters(bookTicket);
        }
    } if (args.front() == "return")
    {
        if(args.size() != 2)
        {
            cout << "Wrong number of arguments" << endl;
            recursive_counter_++;
            parseParameters(bookTicket);
        }
        recursive_counter_ = 0;
        return make_unique<ReturnTicket>(bookTicket, args[1]);
    }
    return nullptr;
}

map<string, string> ConsoleProcessor::authenticateUser()
{
    map <string, string> user;

    cout << "Please enter your username: ";
    getline(cin, user["name"]);

    cout << "Please enter your age: ";
    getline(cin, user["age"]);
    user["age"] = validate_int(user["age"]);
    
    cout << "Please enter your balance (in dollars): ";
    getline(cin, user["balance"]);
    user["balance"] = validate_int(user["balance"]);
    
    return user;
}

string ConsoleProcessor::validate_int(string& param)
{
    while (true)
    {
        try
        {
            stoi(param);
            return param;
        } catch (invalid_argument& e) {
            cout << "Enter an integer parameter" << endl;
            getline(cin, param);
        }
    }
}

bool ConsoleProcessor::getline_wrapper(istream& input, string& line) { 
    return static_cast<bool>(getline(input, line)); 
}

void ConsoleProcessor::printInfo(const map<string,string>& file_info)
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

void ConsoleProcessor::printInfo(const map<string,float>& file_info)
{
    if(file_info.empty())
    {
        cout << "No info found" << endl;
        return;
    }
    
    for (const auto& [key, value] : file_info)
    {
        cout << key << ": " << value << "$" << endl;
    }
}

vector<string> ConsoleProcessor::validate_command(const string& command)
{
    vector<string> args;
    vector<string> options = {"check", "book", "return", "view", "exit"};;
    stringstream ss(command);
    
    string word;
    int arg_count = 0;
    while(ss >> word)
    {
        if(arg_count == 0 && find(options.begin(), options.end(), word) == options.end())
        {
            cout << "Invalid command" << endl;
        } else
        {
            args.push_back(word);
            word.clear();
            arg_count++;
        }
    }
    return args;
}

