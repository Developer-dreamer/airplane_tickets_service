#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <regex>

using namespace std;

class FileProcessor {
public:
    explicit FileProcessor(string file_name);

    vector<map<string, string>> readFile() const;

private:
    const string file_name_;
    map<string, string> splitData(const string& line) const;
};
