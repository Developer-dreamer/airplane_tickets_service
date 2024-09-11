#include <map>
#include <string>

using namespace std;

struct Airplane {
  explicit Airplane(const map<string, string>& flight_info)
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
      for (int i = 0; i < seats_per_row_; i++)
      {
        const char seat_let_id = static_cast<char>('A' + (i - 1));
        price_[key + seat_let_id] = stof(value);
      }

    }
  };

  void ReserveSeat(const string& seat)
  {
    if (find(reserved_seats_.begin(), reserved_seats_.end(), seat) != reserved_seats_.end())
    {
      cout << "Seat is already taken" << endl;
      return;
    }
    reserved_seats_.push_back(seat);
  }

private:
  string date_;
  string flight_num_;
  int seats_per_row_;
  vector<string> reserved_seats_;
  map<string, float> price_;
};
