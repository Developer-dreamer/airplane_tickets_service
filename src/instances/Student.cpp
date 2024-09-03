#include <utility>

#include "../include/Student.h"

Student::Student(string full_name, const int& age, const float& balance, string student_id_card_number, string university_name, string expiration_date)
    : User(std::move(full_name), age, balance),
        student_id_card_number_(std::move(student_id_card_number)),
        university_name_(std::move(university_name)),
        expiration_date_(std::move(expiration_date))
{};

