#pragma once
#include "User.h"
#include "Seat.h"

class PurchaseProcessor {
public:
    PurchaseProcessor(User& user, Seat& seat);

    Ticket Purchase();

    ~PurchaseProcessor() = default;
private:
    User& user_;
    Seat& seat_;

    Ticket process_purchase_();
};
