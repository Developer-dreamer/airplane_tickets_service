#include "RequestTicketInfo.h"

RequestTicketInfo::RequestTicketInfo(shared_ptr<BookingContext> receiver, int view_type, string parameter)
    : receiver_(std::move(receiver)),
        view_type(view_type),
        parameter(std::move(parameter))
{}

void RequestTicketInfo::execute()
{
    switch (view_type){
        // stands for ticket
        case 0: {
                result_.push_back(receiver_->viewTicket(stoi(parameter)));
                break;
            }
        // stands for user or flight
        case 1: {
                // return type will be vector of tickets
                result_ = receiver_->getUser()->getTickets(parameter);
                break;
            }
        default:
            {
                cout << "Something went wrong" << endl;
                break;
            }
    }
}

vector<map<string, string>> RequestTicketInfo::obtainResults() const
{
    return result_;
}
