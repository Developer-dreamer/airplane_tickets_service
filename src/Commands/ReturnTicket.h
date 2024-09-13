#pragma once
#include "BookingContext.h"
#include "ICommand.h"

class ReturnTicket final : public ICommand {
public:
    explicit ReturnTicket(const shared_ptr<BookingContext>& receiver, const string& ticket_id);
    void execute() override;
private:
    const shared_ptr<BookingContext>& receiver_;
    int ticket_id_;
};