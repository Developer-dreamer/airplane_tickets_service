#include "BookTicket.h"

#include "PurchaseProcessor.h"

BookTicket::BookTicket(shared_ptr<BookingContext> receiver, string date, string flight_num, string place, string user_name)
    : receiver_(move(receiver)),
        user_name(move(user_name)),
        date(move(date)),
        flight_num(move(flight_num)),
        place(move(place))
{}

void BookTicket::execute() {
    // obtain user from BookingContext
    shared_ptr<User> buyer = receiver_->getUser();
    shared_ptr<Airplane> flight;
    
    try
    {
        flight = receiver_->getFlight(date, flight_num);
    } catch(runtime_error& e) {
        cout << e.what() << endl;
        return;
    }
    
    // create PurchaseProcessor
    PurchaseProcessor purchase_processor(buyer, flight, place);
    
    // Start purchase
        // ask for specific features
        // increment or decrement price
    Ticket ticket = purchase_processor.purchase();

    // update user instance
    buyer->addTicket(ticket);
    //return;
}