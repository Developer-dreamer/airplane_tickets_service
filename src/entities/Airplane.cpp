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

void Airplane::ReserveSeat(const string& seat, const float& price)
{
    if (find(reserved_seats_.begin(), reserved_seats_.end(), seat) != reserved_seats_.end())
    {
        cout << "Seat is already taken" << endl;
        return;
    }
    if (price_[seat] > price)
    {
        cout << "Not enough money" << endl;
        return;
    }
    reserved_seats_.push_back(seat);
}

map<string, string> Airplane::getFlightInfo() const
{
    map<string, string> info;
    info["date"] = date_;
    info["flight_id"] = flight_num_;
}

vector<int> Airplane::getSeatNumbers(const string& seat) const
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
