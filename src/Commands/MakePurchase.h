#include "ICommand.h"
#include "BookingContext.h"


class MakePurchase final : public ICommand {
public:
    explicit MakePurchase(const BookingContext& receiver);
    
    void execute() override;

    User getUpdatedUser() const;

private:
    const BookingContext& receiver_;
    User buyer_;
    string seat_id_;
};
