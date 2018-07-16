#include "Kaleidoscope-LEDEffect-Chase.h"

namespace kaleidoscope {
void LEDChaseEffect::update(void) {
  if (current_chase_counter++ < chase_threshold) {
    return;
  }
  current_chase_counter = 0;
  ::LEDControl.setCrgbAt(pos - (chase_sign * chase_pixels), {0, 0, 0});
  ::LEDControl.setCrgbAt(pos, {0, 0, 0});

  pos += chase_sign;
  if (pos >= (LED_COUNT - 1) || pos <= 0) {
    chase_sign = -chase_sign;
  }
  ::LEDControl.setCrgbAt(pos, {0, 0, 255});
  ::LEDControl.setCrgbAt(pos - (chase_sign * chase_pixels), {255, 0, 0});
}
}

kaleidoscope::LEDChaseEffect LEDChaseEffect;
