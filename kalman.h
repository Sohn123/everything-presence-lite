#include <tuple>
#include <vector>
#include <algorithm> // for std::all_of
#include <cstdint>   // for uint8_t

std::tuple<float, float> kalman_update(float measurement, float estimate, float error_estimate, float process_noise, float measurement_noise) {
  // Prediction update
  error_estimate += process_noise;

  // Measurement update
  float kalman_gain = error_estimate / (error_estimate + measurement_noise);
  estimate = estimate + kalman_gain * (measurement - estimate);
  error_estimate = (1 - kalman_gain) * error_estimate;

  return std::make_tuple(estimate, error_estimate);
}

bool is_any_not_zero(const std::vector<uint8_t>& vec, size_t start, size_t end) {
    if (start > end || end > vec.size()) return false; // basic bounds check
    return std::any_of(vec.begin() + start, vec.begin() + end, [](uint8_t b) {
        return b != 0;
    });
}