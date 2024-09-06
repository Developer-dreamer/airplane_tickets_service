#pragma once
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileProcessor {
public:
    explicit FileProcessor(string file_name);

    vector<string> readFile() const;

private:
    const string file_name_;
};
