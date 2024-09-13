#pragma once
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

class FileProcessor {
public:
    explicit FileProcessor(const string& file_name);

    vector<map<string, string>> readFile();
    
    ~FileProcessor();
private:
    ifstream file_stream_;
    map<string, string> splitData(const string& line) const;
};
