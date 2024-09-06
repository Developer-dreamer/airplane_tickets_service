#include "../include/FileProcessor.h"

FileProcessor::FileProcessor(string file_name)
    : file_name_(move(file_name))
{}

vector<string> FileProcessor::readFile() const
{
    vector<string> file_text;
    string line;
    
    ifstream file(file_name_);
    
    while (getline(file, line))
    {
        if(!line.empty())
        {
            file_text.push_back(line);
        }
    }

    return file_text;
};

