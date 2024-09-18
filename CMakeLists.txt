cmake_minimum_required(VERSION 3.29)
project(airplane_tickets_service CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/6dae7eb4a5c3a169f3e298392bff4680224aa94a.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(.)
include_directories("src/entities")
include_directories("include")

add_executable(airplane_tickets_service
        src/entities/User.cpp
        src/main.cpp
        include/User.h
        include/Ticket.h
        src/entities/Ticket.cpp
        src/processors/PurchaseProcessor.cpp
        include/PurchaseProcessor.h
        include/FileProcessor.h
        src/processors/FileProcessor.cpp
        include/ConsoleProcessor.h
        src/processors/ConsoleProcessor.cpp
        include/ICommand.h
        include/BookingContext.h
        src/Commands/RequestFlightInfo.h
        src/Commands/RequestFlightInfo.cpp
        src/Commands/BookTicket.h
        src/Commands/BookTicket.cpp
        src/processors/BookingContext.cpp
        src/entities/Airplane.cpp
        include/Airplane.h
        src/Commands/RequestTicketInfo.h
        src/Commands/RequestTicketInfo.cpp
        src/Commands/ReturnTicket.h
        src/Commands/ReturnTicket.cpp
        tests/ConsoleProcessorTests.cpp
)

target_link_libraries(
        airplane_tickets_service
        GTest::gtest_main
        GTest::gmock_main
)

include(GoogleTest)
gtest_discover_tests(airplane_tickets_service)
