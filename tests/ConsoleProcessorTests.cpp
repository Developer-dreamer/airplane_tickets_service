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

class MockConsoleProcessor : public ConsoleProcessor {
public:
    MOCK_METHOD(bool, getline_wrapper, (istream&, string&));
};



TEST(ConsoleProcessor, HandleCheckCommand)
{
    shared_ptr<BookingContext> bookTicket = make_shared<BookingContext>();

    MockConsoleProcessor mockConsoleProcessor;
    std::istringstream input("Serafym\n18\n500\ncheck 15.10.2022 QW12\n"); 
    EXPECT_CALL(mockConsoleProcessor, getline_wrapper(input, _))
        .WillRepeatedly(Return(true));
    
    unique_ptr<ICommand> command = ConsoleProcessor::parseParameters(bookTicket);

    unique_ptr<RequestFlightInfo> expectedCommand = make_unique<RequestFlightInfo>(bookTicket, "15.10.2022", "QW12");
    ASSERT_EQ(command, expectedCommand);
}
