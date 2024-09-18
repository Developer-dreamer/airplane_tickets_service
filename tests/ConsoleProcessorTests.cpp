#include <gtest/gtest.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <gmock/gmock.h>

#include "include/ConsoleProcessor.h"
#include "include/BookingContext.h"
#include "src/Commands/RequestFlightInfo.h"

using namespace std;
using namespace testing;
//
// class MockConsoleProcessor : public ConsoleProcessor {
// public:
//     MOCK_METHOD0(authenticateUser, std::map<std::string, std::string>());
// };



TEST(ConsoleProcessor, HandleCheckCommand)
{
     // shared_ptr<BookingContext> bookTicket = make_shared<BookingContext>();
     // stringstream input("Serafym\n18\n500\ncheck 15.10.2022 QW12\n");
     // streambuf* oldCin = cin.rdbuf(input.rdbuf());
     //
     // unique_ptr<ICommand> command = ConsoleProcessor::parseParameters(bookTicket);
     //
     // cin.rdbuf(oldCin);
     //
     // unique_ptr<RequestFlightInfo> expectedCommand = make_unique<RequestFlightInfo>(bookTicket, "15.10.2022", "QW12");
     // ASSERT_EQ(command, expectedCommand);
     //
     // // Restore cin
     // std::cin.rdbuf(oldCin);
}
