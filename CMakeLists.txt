cmake_minimum_required(VERSION 3.29)
project(airplane_tickets_service CXX)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 14)

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
        src/Commands/MakePurchase.cpp
)