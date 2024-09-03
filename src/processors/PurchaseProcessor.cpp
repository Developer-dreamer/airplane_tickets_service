#include "../include/PurchaseProcessor.h"

PurchaseProcessor::PurchaseProcessor(User& user, Seat& seat)
    : user_(user),
        seat_(seat)
{};
