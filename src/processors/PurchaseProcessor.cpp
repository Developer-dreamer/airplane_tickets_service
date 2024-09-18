#include "../include/PurchaseProcessor.h"

PurchaseProcessor::PurchaseProcessor(shared_ptr<User> user, string passenger, shared_ptr<Airplane> airplane, string seat)
    : user_(user),
        passenger_(std::move(passenger)),
        airplane_(airplane),
        seat_id_(std::move(seat))
{};

Ticket PurchaseProcessor::purchase(const int& purchase_id) const
{
    float reservedPrice;
    try
    {
        reservedPrice = airplane_->ReserveSeat(seat_id_, user_->getBalance());
    } catch(runtime_error& e) {
        cout << e.what() << endl;
        return {-1, "", "", "", "", 0};
    }

    map<string, string> flight_info = airplane_->getFlightInfo();

    user_->writeOffFunds(reservedPrice);

    Ticket ticket(purchase_id, flight_info["date"], flight_info["flight_id"], seat_id_, passenger_, reservedPrice);

    return ticket;
}
