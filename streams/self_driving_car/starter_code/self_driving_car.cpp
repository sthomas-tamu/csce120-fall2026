#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

double calculate_average(const std::vector<double>& values);
double calculate_median(const std::vector<double>& values);

// Function to process sensor readings and return reliable distance
// Throws runtime_error if multiple sensors fail
double process_sensor_readings(const std::vector<double>& readings,
  double error_threshold, int outliers_allowed) {
  // TODO(@Student)

  // Step 1: Calculate median of all sensors

  // Step 2: Find number of outliers
  //         (sensors that deviate more than error_threshold from median)
  //         Store good readings in a new vector

  // Step 3: Handle based on number of outliers
  //         If too many outliers, throw runtime exception
  //         Otherwise report the average of the good readings

  return 0;
}

int main() {
  try {
    // Open the three sensor files
    std::ifstream lidar_file("lidar.txt");
    std::ifstream camera_file("camera.txt");
    std::ifstream radar_file("radar.txt");

    // Check if files opened successfully
    if (!lidar_file) {
      throw std::runtime_error("Error: Could not open lidar.txt");
    }
    if (!camera_file) {
      throw std::runtime_error("Error: Could not open camera.txt");
    }
    if (!radar_file) {
      throw std::runtime_error("Error: Could not open radar.txt");
    }

    // Read from sensors until any file reaches end
    int reading_num = 0;

    double lidar_dist = 0;
    double camera_right_dist = 0;
    double camera_center_dist = 0;
    double camera_left_dist = 0;
    double radar_dist = 0;

    while ( (lidar_file >> lidar_dist) &&
            (camera_file >> camera_right_dist >> camera_center_dist >> camera_left_dist) &&
            (radar_file >> radar_dist) ) {
      // Store sensor readings
      std::vector<double> sensor_readings = {lidar_dist, camera_right_dist,
        camera_center_dist, camera_left_dist, radar_dist};

      // Process readings with exception handling
      // Allow up to 2 readings that deviate more than 1 foot
      std::cout << "Reading " << reading_num << ": ";

      // TODO(@Student) attempt to process_sensor_readings
      //   Report average distance for self-driving mode
      //   Catch any errors process_sensor_readings might throw and report error

      std::cout << std::endl;

      // Advance reading counter
      reading_num++;
    }

    // Close files
    lidar_file.close();
    camera_file.close();
    radar_file.close();
  }
  catch (const std::runtime_error& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}


double calculate_average(const std::vector<double>& values) {
  double sum = 0.0;
  for (double val : values) {
    sum += val;
  }
  return sum / values.size();
}


double calculate_median(const std::vector<double>& values) {
  std::vector<double> sorted(values);
  std::sort(sorted.begin(), sorted.end());
  int middle_index = sorted.size() / 2;
  if (sorted.size() % 2 == 1) {  // odd number of values, median is middle index
    return sorted.at(middle_index);
  } else {  // even number of values, median is average of middle 2 indices
    return (sorted.at(middle_index - 1) + sorted.at(middle_index) ) / 2;
  }
}
