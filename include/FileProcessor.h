#pragma once
#include <iostream>
#include <map>

using namespace std;

class FileProcessor {
public:
    FileProcessor() = default;

private:
    const string file_name_;
    map<string, string> request_result_;
};
