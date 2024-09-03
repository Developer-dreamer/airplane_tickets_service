#include <utility>

#include "../include/User.h"

User::User(string full_name, const int& age, const float& balance)
    : full_name_(std::move(full_name)),
      age_(age),
      balance_(balance)
{};
