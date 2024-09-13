#include "ReturnTicket.h"

ReturnTicket::ReturnTicket(shared_ptr<BookingContext> receiver, const string& ticket_id)
    : receiver_(receiver),
      ticket_id_(stoi(ticket_id))
{}

void ReturnTicket::execute()
{
    try
    {
        receiver_->returnTicket(ticket_id_);
    } catch (exception& e)
    {
        cout << e.what() << endl;
    } cout << "Ticket returned" << endl;
}