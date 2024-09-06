#include "../include/PurchaseProcessor.h"

PurchaseProcessor::PurchaseProcessor(const User& user, string seat)
    : user_(user),
        seat_id_(move(seat))
{};

Ticket PurchaseProcessor::purchase() {
    
}