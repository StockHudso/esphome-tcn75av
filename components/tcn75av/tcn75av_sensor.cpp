#include "tcn75av_sensor.h"
#include "esphome/core/log.h"

namespace esphome {
namespace tcn75av {

static const char *TAG = "tcn75av";

void TCN75AVSensor::setup() {
  ESP_LOGI(TAG, "Initializing TCN75AV temperature sensor");
}

void TCN75AVSensor::update() {
  uint8_t data[2];

  // Temperature register is 0x00
  if (!this->read_register(0x00, data, 2)) {
    ESP_LOGW(TAG, "Failed to read temperature register");
    return;
  }

  // MSB first
  int16_t raw = (data[0] << 8) | data[1];

  // Upper 12 bits, signed
  raw >>= 4;

  float temperature = raw * 0.0625f;

  ESP_LOGD(TAG, "Raw=%d  Temp=%.2f°C", raw, temperature);

  this->publish_state(temperature);
}

}  // namespace tcn75av
}  // namespace esphome
