#pragma once
#include <iostream>
#include <map>
#include <sstream>
#include <string>


using namespace std;

struct Airplane {
  Airplane() = default;
  explicit Airplane(const map<string, string>& flight_info);

  float ReserveSeat(const string& seat, const float& price);
  void CancelSeat(const string& seat_id);
  
  [[nodiscard]] map<string, string> getFlightInfo() const;
  
private:
  string date_;
  string flight_num_;
  int seats_per_row_{};
  vector<string> reserved_seats_;
  map<string, float> price_;

  static vector<int> getSeatNumbers(const string& seat) ;
};
