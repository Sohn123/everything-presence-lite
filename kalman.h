#include <tuple>
std::tuple<float, float> kalman_update(float measurement, float estimate, float error_estimate, float process_noise, float measurement_noise) {
  // Prediction update
  error_estimate += process_noise;

  // Measurement update
  float kalman_gain = error_estimate / (error_estimate + measurement_noise);
  estimate = estimate + kalman_gain * (measurement - estimate);
  error_estimate = (1 - kalman_gain) * error_estimate;

  return std::make_tuple(estimate, error_estimate);
}