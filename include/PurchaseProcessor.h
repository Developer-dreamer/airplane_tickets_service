#pragma once
#include <iostream>
#include "User.h"
#include "Airplane.h"

using namespace std;

class PurchaseProcessor {
public:
    PurchaseProcessor(shared_ptr<User> user, string passenger, shared_ptr<Airplane> airplane, string seat);

    Ticket purchase(const int& purchase_id) const;

    ~PurchaseProcessor() = default;
private:
    shared_ptr<User> user_;
    string passenger_;
    shared_ptr<Airplane> airplane_;
    string seat_id_;
};
