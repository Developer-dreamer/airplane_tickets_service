#pragma once
#include "User.h"
#include "Airplane.h"

class PurchaseProcessor {
public:
    PurchaseProcessor(shared_ptr<User> user, shared_ptr<Airplane> airplane, string seat);

    Ticket purchase();

    ~PurchaseProcessor() = default;
private:
    shared_ptr<User> user_;
    shared_ptr<Airplane> airplane_;
    string seat_id_;
};
