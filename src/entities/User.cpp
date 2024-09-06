#include <utility>

#include "../include/User.h"

User::User()
    : age_(0),
      balance_(0)
{
}

User::User(map<string, string> user_info)
{
    full_name_ = user_info["full_name"];
    age_ = stoi(user_info["age"]);
    balance_ = stof(user_info["balance"]);
}

void User::addTicket(const Ticket& ticket)
{
    ticket_ = ticket;
}

float User::getBalance() const
{
    return balance_;
};
