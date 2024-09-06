#include <utility>

#include "../include/User.h"

User::User()
    : age_(0),
      balance_(0)
{
}

User::User(string full_name, const int& age, const float& balance)
    : full_name_(std::move(full_name)),
      age_(age),
      balance_(balance),
      ticket_()
{}

void User::addTicket(Ticket ticket)
{
    ticket_ = ticket;
}

float User::getBalance() const
{
    return balance_;
};
