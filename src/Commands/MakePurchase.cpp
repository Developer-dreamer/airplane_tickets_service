#include "MakePurchase.h"

#include "PurchaseProcessor.h"

MakePurchase::MakePurchase(const BookingContext& receiver) : receiver_(receiver){}

void MakePurchase::execute()
{
    try {
        buyer_ = receiver_.getUser();
        seat_id_ = receiver_.getSeat();
    } catch (exception& e) {
        cout << e.what() << endl;
        exit(-1);
    }
    
    PurchaseProcessor purchase(buyer_, seat_id_);

    const Ticket ticket = purchase.purchase();

    buyer_.addTicket(ticket);
}

User MakePurchase::getUpdatedUser() const
{
    return buyer_;
}
