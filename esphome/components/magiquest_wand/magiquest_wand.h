#pragma once

#include "esphome/core/component.h"

class MagiquestBinarySensor : public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
  void set_pin(int pin) { this->pin_ = pin; }
  void set_wandid(int wandId) { this->wand_id_ = wandId; }

 protected:
  InternalGPIOPin *pin_;
  int wand_id_{0x0};
}
