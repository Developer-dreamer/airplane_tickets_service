#include "../include/PurchaseProcessor.h"

PurchaseProcessor::PurchaseProcessor(shared_ptr<User> user, shared_ptr<Airplane> airplane, string seat)
    : user_(move(user)),
        airplane_(move(airplane)),
        seat_id_(move(seat))
{};

Ticket PurchaseProcessor::purchase() {
    
}
