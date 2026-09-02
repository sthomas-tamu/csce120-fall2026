#include <iostream>
#include <vector>

struct HiLoTemperature {
  double high = 0;
  double low = 0;
};

int main() {
  std::vector<HiLoTemperature> daily_temperatures;

  // read in temperatures
  std::cout << "Enter high and low temperatures for each day. "
    << "Enter a non-number to stop.\n";
  double high = 0;
  double low = 0;
  while (std::cin >> high >> low) {
    if (high < low) {
      std::cout << "Error, temperatures are out of order. "
        << "The high for the day comes first. Exiting.\n";
      return -1;
    }
    daily_temperatures.push_back({high, low});
  }

  // print out temperatures
  std::cout << "Daily high and low temperatures:\n";
  for (HiLoTemperature temperature : daily_temperatures) {
    std::cout << "\t(" << temperature.high << ", " << temperature.low << ")\n";
  }

  // count number of days below freezing
  unsigned int below_freezing = 0;
  for (HiLoTemperature temperature : daily_temperatures) {
    if (temperature.low < 32) {
      below_freezing++;
    }
  }
  std::cout << "Days below freezing: " << below_freezing << std::endl;

  // report hottest day
  if (!daily_temperatures.empty()) {
    unsigned int hottest = 0;
    for (unsigned int i = 1; i < daily_temperatures.size(); ++i) {
      if (daily_temperatures.at(i).high > daily_temperatures.at(hottest).high) {
        hottest = i;
      }
    }
    std::cout << "Hottest is day " << hottest << " with temperature "
      << daily_temperatures.at(hottest).high << std::endl;
  } else {
    std::cout << "Cannot report hottest day, no temperatures provided.\n";
  }

  // if at least 3 daily temperatures, predict next day's temperatures
  // as average of last 3 days, otherwise give error message
  if (daily_temperatures.size() >= 3) {
    HiLoTemperature prediction;
    for (unsigned int i = 0; i < 3; ++i) {
      unsigned int index = daily_temperatures.size() - 1 - i;
      prediction.high += daily_temperatures.at(index).high;
      prediction.low += daily_temperatures.at(index).low;
    }
    prediction.high /= 3;
    prediction.low /= 3;
    std::cout << "Forcast: high of " << prediction.high
      << ", low of " << prediction.low << std::endl;
  } else {
    std::cout << "Need at least 3 days of temperatures to make a forcast\n";
  }

  return 0;
}
