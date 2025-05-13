#include "esphome/core/log.h"
#include "magiquest_wand.h"

namespace esphome {
namespace magiquest_wand {
static const char *TAG = "magiquest_wand.ir" IRrecv irrecv(pin_)

    void
    MagiquestBinarySensor::setup() {
  irrecv.enableIRIn();
  this->publish_initial_state(false);
}

void MagiquestBinarySensor::loop() {
  if (irrecv.decode()) {
    if (irrecv.decodeMagiQuest()) {
      ESP_LOGI(TAG, "Received Magiquest Data");
      ESP_LOGI(TAG, "WandId: 0x%08", irrecv.decodedIRData.decodedRawData);
            ESP_LOGI(TAG, "Magnitude"), irrecv.command);
    }
  }

  this->publish_state(status);
}

void MagiquestBinarySensor::dump_config() {
  ESP_LOGCONFIG(TAG, "Magiquest Wand");
  LOG_PIN(TAG, "pin = ", this->pin_);
  ESP_LOGCONFIG(TAG, "wand id = 0x%08", wandid_);
}

}  // namespace magiquest_wand
}  // namespace esphome