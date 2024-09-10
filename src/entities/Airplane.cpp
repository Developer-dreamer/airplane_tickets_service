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
      if (find(parsed_info.begin(), parsed_info.end(), key) != parsed_info.end())
      {
        continue;
      }
      for (int i = 0; i < seats_per_row_; i++)
      {
        const char seat_let_id = static_cast<char>('A' + (i - 1));
        seats_[key + seat_let_id] = false;
      }
      price_[key] = stof(value);
    }
  };

private:
  string date_;
  string flight_num_;
  int seats_per_row_;
  map<string, bool> seats_;
  map<string, float> price_;
};
