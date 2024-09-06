#include "ICommand.h"
#include "PurchaseProcessor.h"

class ProcessPurchase final : public ICommand {
public:
    explicit ProcessPurchase(BookingContext receiver);
    
    void execute() override;

private:
    BookingContext& receiver_;
    User buyer_;
    Seat seat_;
};
