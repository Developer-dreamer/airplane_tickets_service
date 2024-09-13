#include "Airplane.h"


Airplane::Airplane(const map<string, string>& flight_info)
{
    date_ = flight_info.at("date");
    flight_num_ = flight_info.at("flight_id");
    seats_per_row_ = stoi(flight_info.at("seats_per_row"));
    vector<string> parsed_info = {"date", "flight_id", "seats_per_row"};
    for (const auto& [key, value] : flight_info)
    {
        // skip arguments if they are not about price
        if (find(parsed_info.begin(), parsed_info.end(), key) != parsed_info.end())
        {
            continue;
        }
        vector<int> seat_numbers = getSeatNumbers(key);
        for (int i = seat_numbers[0]; i <= seat_numbers[1]; i++)
        {
            for (int j = 0; j < seats_per_row_; j++)
            {
                const string seat_num = to_string(i);
                const string seat_let(1, 'A' + j);
                price_[seat_num + seat_let] = stof(value);
            }
        }
    }
}

float Airplane::ReserveSeat(const string& seat, const float& budget)
{
    if (reserved_seats_.find(seat) != reserved_seats_.end())
    {
        throw runtime_error("Seat already reserved");
    } if (price_.find(seat) == price_.end())
    {
        throw runtime_error("Seat does not exist");
    }
    if (price_[seat] > budget)
    {
        throw runtime_error("Not enough money");
    }
    reserved_seats_[seat] = price_[seat];
    float price = price_[seat];
    price_.erase(seat);
    return price;
}

void Airplane::CancelSeat(const string& seat_id)
{
    auto it = reserved_seats_.find(seat_id);
    if (it == reserved_seats_.end())
    {
        throw runtime_error("Seat was not reserved");
    }
    price_[seat_id] = reserved_seats_[seat_id];
    reserved_seats_.erase(it);
}

map<string, float> Airplane::getAllAvailableSeats() const
{
    return price_;
}

map<string, string> Airplane::getFlightInfo() const
{
    map<string, string> info;
    info["date"] = date_;
    info["flight_id"] = flight_num_;
    return info;
}

vector<int> Airplane::getSeatNumbers(const string& seat) 
{
    vector<int> seat_numbers;
    stringstream ss(seat);
    
    string start_with_;
    string end_with_;
    
    getline(ss, start_with_, '-');
    getline(ss, end_with_, '-');

    try
    {
        seat_numbers.push_back(stoi(start_with_));
        seat_numbers.push_back(stoi(end_with_));
    } catch (exception& e)
    {
        cout << "Invalid seat number" << endl;
    }
    return seat_numbers;
}
