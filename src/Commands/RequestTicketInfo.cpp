#include "RequestTicketInfo.h"

RequestTicketInfo::RequestTicketInfo(shared_ptr<BookingContext> receiver, int view_type, string parameter)
    : receiver_(receiver),
        view_type(view_type),
        parameter(move(parameter))
{}

void RequestTicketInfo::execute()
{
    if (view_type)
    {
        result_ = receiver_->getUser()->getTickets(parameter);
    } else
    {
        result_.push_back(receiver_->viewTicket(stoi(parameter)));
    } //else
    // {
    //     cout << "Something went wrong" << endl;
    //     
    // }
    
    
}

vector<map<string, string>> RequestTicketInfo::obtainResults() const
{
    return result_;
}
