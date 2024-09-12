#include "BookTicket.h"
#include "PurchaseProcessor.h"

BookTicket::BookTicket(shared_ptr<BookingContext> receiver, string date, string flight_num, string place, string user_name)
    : receiver_(std::move(receiver)),
        user_name(std::move(user_name)),
        date(std::move(date)),
        flight_num(std::move(flight_num)),
        place(std::move(place))
{}

void BookTicket::execute() {
    // obtain user from BookingContext
    const shared_ptr<User> buyer = receiver_->getUser();
    shared_ptr<Airplane> flight;
    
    try
    {
        flight = receiver_->getFlight(date, flight_num);
    } catch(runtime_error& e) {
        cout << e.what() << endl;
        return;
    }
    
    // create PurchaseProcessor
    const PurchaseProcessor purchase_processor(buyer, flight, place);
    
    // Start purchase
    
    const Ticket ticket = purchase_processor.purchase(receiver_->updatePurchaseId());
    if (ticket.getId() == -1)
    {
        cout << "Purchase failed" << endl;
        return;
    }

    // update user instance
    buyer->addTicket(ticket);
    //return;
}