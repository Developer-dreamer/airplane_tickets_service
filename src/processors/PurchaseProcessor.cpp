#include "../include/PurchaseProcessor.h"

PurchaseProcessor::PurchaseProcessor(shared_ptr<User> user, shared_ptr<Airplane> airplane, string seat)
    : user_(move(user)),
        airplane_(move(airplane)),
        seat_id_(move(seat))
{};

Ticket PurchaseProcessor::purchase() {
    float reservedPrice;
    try
    {
        reservedPrice = airplane_->ReserveSeat(seat_id_, user_->getBalance());
    } catch(runtime_error& e) {
        cout << e.what() << endl;
        return {"", "", "", 0};
    }

    map<string, string> flight_info = airplane_->getFlightInfo();

    if (user_->getAge() < 16)
    {
        reservedPrice *= 0.5;
    }

    user_->writeOffFunds(reservedPrice);

    Ticket ticket(flight_info["flight_id"], flight_info["date"], seat_id_, reservedPrice);

    return ticket;
}
