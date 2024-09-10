#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

class FileProcessor {
public:
    explicit FileProcessor(const string& file_name);

    map<string, string> searchFlight(const string& date_to_search, const string& flight_to_search);
    ~FileProcessor();
private:
    ifstream file_stream_;
    map<string, string> splitData(const string& line, const string& date_to_search, const string& flight_to_search) const;
};
