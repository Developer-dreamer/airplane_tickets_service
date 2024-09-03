#pragma once
#include <iostream>
#include <map>

using namespace std;

union JsonValue {
    int i;
    double d;
    map<string, JsonValue>* json;  
};