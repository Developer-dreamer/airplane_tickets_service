#pragma once
#include <variant>
#include <iostream>
#include "BookingContext.h"
#include "ICommand.h"

class RequestTicketInfo final : public ICommand{
public:
  RequestTicketInfo(shared_ptr<BookingContext> receiver, int view_type, string parameter);
  void execute() override;

  int view_type;
  
  [[nodiscard]] vector<map<string, string>> obtainResults() const;
private:
  shared_ptr<BookingContext> receiver_;
  string parameter;
  // 0 stands for ticket, 1 stands for user, 2 stands for flight
  vector<map<string, string>> result_;
};