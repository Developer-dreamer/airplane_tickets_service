#pragma once
#include <iostream>
#include "User.h"
#include "Airplane.h"

using namespace std;

class PurchaseProcessor {
public:
    PurchaseProcessor(shared_ptr<User> user, shared_ptr<Airplane> airplane, string seat);

    Ticket purchase() const;

    ~PurchaseProcessor() = default;
private:
    shared_ptr<User> user_;
    shared_ptr<Airplane> airplane_;
    string seat_id_;
};
