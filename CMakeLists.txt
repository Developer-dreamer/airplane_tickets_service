cmake_minimum_required(VERSION 3.29)
project(airplane_tickets_service CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)
include_directories("src/instances")
include_directories("include")

add_executable(airplane_tickets_service
        src/instances/User.cpp
        src/instances/Student.cpp
        src/main.cpp
        include/Student.h
        include/User.h
        include/Ticket.h
        src/instances/Ticket.cpp
        include/Flight.h
        src/instances/Flight.cpp
        src/instances/Seat.cpp
        include/Seat.h
        src/processors/PurchaseProcessor.cpp
        include/PurchaseProcessor.h
        include/FileProcessor.h
        src/processors/FileProcessor.cpp
        FileProcessorHelper/JsonParser.h
        FileProcessorHelper/JsonParser.cpp
        include/ConsoleProcessor.h
        src/processors/ConsoleProcessor.cpp
)