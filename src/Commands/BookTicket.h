#pragma once
#include "BookingContext.h"
#include "ICommand.h"

class BookTicket final : public ICommand {
public:
    BookTicket(const BookingContext& receiver,string date, string flight_num, string place, string user_name);
    void execute() override;
private:
    const BookingContext& receiver_;
    string user_name;
    string date;
    string flight_num;
    string place;
};