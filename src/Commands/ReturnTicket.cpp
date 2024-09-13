#include "ReturnTicket.h"

ReturnTicket::ReturnTicket(const shared_ptr<BookingContext>& receiver, const string& ticket_id)
    : receiver_(receiver),
      ticket_id_(stoi(ticket_id))
{}

void ReturnTicket::execute()
{
    receiver_->returnTicket(ticket_id_);
}