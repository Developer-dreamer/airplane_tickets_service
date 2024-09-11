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
    reserved_tickets_.push_back(ticket);
}

float User::getBalance() const
{
    return balance_;
}

int User::getAge() const
{
    return age_;
}

void User::writeOffFunds(float amount)
{
    balance_ -= amount;
};
