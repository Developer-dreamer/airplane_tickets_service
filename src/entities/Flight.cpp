#include <string>

using namespace std;
struct Flight {
    string flight_id_;
    string departure_airport_;
    string arrival_airport_;
    string departure_time_;
    string arrival_time_;
    string airline_;
    int seats_amount_{};
};
