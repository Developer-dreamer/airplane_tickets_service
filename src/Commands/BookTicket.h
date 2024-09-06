#pragma once
#include "BookingContext.h"
#include "ICommand.h"

class BookTicket final : public ICommand {
public:
    explicit BookTicket(BookingContext& receiver);
    void execute() override;
private:
    BookingContext& receiver_;
};