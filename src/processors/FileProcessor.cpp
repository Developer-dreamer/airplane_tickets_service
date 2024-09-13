#include "../include/FileProcessor.h"

FileProcessor::FileProcessor(const string& file_name)
    : file_stream_(file_name)
{
    if (!file_stream_.is_open()) {
        throw runtime_error("File not found");
    }
}

FileProcessor::~FileProcessor()
{
    file_stream_.close();
}

vector<map<string, string>> FileProcessor::readFile()
{
    vector<map<string, string>> file_text;
    string line;
    
    while (getline(file_stream_, line))
    {
        map<string, string> data = splitData(line);
        file_text.push_back(data);
    }
    
    return file_text;
}

map<string, string> FileProcessor::splitData(const string& line) const 
{
    map<string, string> data;

    stringstream ss(line);
    string word;
    
    int word_id  = 0;
    string seat_temp;
    
    const vector<string> keys = {"date", "flight_id", "seats_per_row"};

    while (ss >> word) {
        if (word_id < 3) {
            data[keys[word_id]] = word;
        } else {
            if (word_id % 2 == 1) {
                seat_temp = word;
            } else
            {
                data[seat_temp] = word;
                seat_temp.clear();
            }
        }
        word_id++;
        word.clear();
    }

    return data;
}

