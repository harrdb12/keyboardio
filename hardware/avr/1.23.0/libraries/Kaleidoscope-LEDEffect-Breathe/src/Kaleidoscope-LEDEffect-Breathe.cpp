#include "Kaleidoscope-LEDEffect-Breathe.h"

namespace kaleidoscope {
void LEDBreatheEffect::update(void) {
  cRGB color = breath_compute();
  ::LEDControl.set_all_leds_to(color);
}
}

kaleidoscope::LEDBreatheEffect LEDBreatheEffect;
