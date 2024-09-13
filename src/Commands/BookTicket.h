#pragma once
#include "BookingContext.h"
#include "ICommand.h"

class BookTicket final : public ICommand {
public:
    BookTicket(shared_ptr<BookingContext> receiver,string date, string flight_num, string place, string passenger);
    void execute() override;
private:
    shared_ptr<BookingContext> receiver_;
    string passenger_;
    string date;
    string flight_num;
    string place;
};