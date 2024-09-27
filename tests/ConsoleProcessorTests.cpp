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
    
    // EXPECT_CALL(mockConsoleProcessor, getline_wrapper(_, _))
    //     .Times(3)
    //     .WillOnce(DoAll(SetArgReferee<1>("Serafym"), Return(true)))
    //     .WillOnce(DoAll(SetArgReferee<1>("18"), Return(true)))
    //     .WillOnce(DoAll(SetArgReferee<1>("500"), Return(true)));

    // EXPECT_CALL(mockConsoleProcessor, getline_wrapper(_, _))
    //     .WillOnce(DoAll(SetArgReferee<1>("check 15.10.2022 QW12"), Return(true)));

    bool isSuccess;
    unique_ptr<ICommand> command = MockConsoleProcessor::parseParameters(bookTicket);
    
    // if ()
    // {
    //     isSuccess = true;
    // }

    unique_ptr<RequestFlightInfo> expectedCommand = make_unique<RequestFlightInfo>(bookTicket, "15.10.2022", "QW12");
    ASSERT_EQ(command, expectedCommand);

}
