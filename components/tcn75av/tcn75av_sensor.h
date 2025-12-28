#pragma once

#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace tcn75av {

class TCN75AVSensor : public PollingComponent,
                      public sensor::Sensor,
                      public i2c::I2CDevice {
 public:
  void setup() override;
  void update() override;
};

}  // namespace tcn75av
}  // namespace esphome

