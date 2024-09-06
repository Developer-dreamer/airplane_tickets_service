#pragma once
#include "User.h"

class PurchaseProcessor {
public:
    PurchaseProcessor(const User& user, string seat);

    Ticket purchase();

    ~PurchaseProcessor() = default;
private:
    User user_;
    string seat_id_;
};
