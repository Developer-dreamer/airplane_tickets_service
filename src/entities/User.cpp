#include "../include/User.h"

User::User()
    : age_(0),
      balance_(0)
{
}

User::User(map<string, string> user_info)
{
    full_name_ = user_info["name"];
    age_ = stoi(user_info["age"]);
    balance_ = stof(user_info["balance"]);
}

void User::addTicket(const Ticket& ticket)
{
    reserved_tickets_.push_back(ticket);
}

void User::removeTicket(const int& ticket_id)
{
    for (auto it = reserved_tickets_.begin(); it != reserved_tickets_.end(); ++it)
    {
        if (it->getId() == ticket_id)
        {
            reserved_tickets_.erase(it);
            return;
        }
    }
}

void User::refund(const float& amount)
{
    balance_ += amount;
}

float User::getBalance() const
{
    return balance_;
}

int User::getAge() const
{
    return age_;
}

map<string, string> User::getTicket(int index) const
{
    for (const auto& ticket : reserved_tickets_)
    {
        if (ticket.getId() == index)
        {
            return ticket.obtainTicketInfo();
        }
    }
    return {};
}

vector<map<string, string>> User::getTickets(const string& parameter) const {
    vector<map<string, string>> tickets;

    tickets.reserve(reserved_tickets_.size());
    for (const auto& ticket : reserved_tickets_) {
        map<string, string> is_right_ticket = ticket.obtainTicketInfo();
        
        bool shouldProcess = false;
        for (const auto& kv : is_right_ticket) {
            if (kv.second == parameter) {
                shouldProcess = true;
                break;
            }
        }

        if (shouldProcess) {
            tickets.push_back(ticket.obtainTicketInfo());
        }
    }

    return tickets;
}

vector<map<string, string>> User::getTicketsByFlight(const string& flight_id) const
{
    vector<map<string, string>> tickets;
    for (const auto& ticket : reserved_tickets_)
    {
        if (ticket.obtainTicketInfo()["flight_number"] == flight_id)
        {
            tickets.push_back(ticket.obtainTicketInfo());
        }
    }
    return tickets;
}

void User::writeOffFunds(float amount)
{
    balance_ -= amount;
};
