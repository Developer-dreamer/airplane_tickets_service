#pragma once
#include <iostream>
#include <utility>
#include "User.h"

using namespace std;

class Student : User {
public:

    // ak about the best approach: to define User,
    // then cast and define private fields of Student
    // or define student with all fields for user
    // and student calling the User constructor
    
    Student(string full_name, const int& age, const float& balance, string student_id_card_number, string university_name, string expiration_date);
    
    void get_sale() const;

    ~Student() = default;
private:
    string student_id_card_number_;
    string university_name_;
    string expiration_date_;
};