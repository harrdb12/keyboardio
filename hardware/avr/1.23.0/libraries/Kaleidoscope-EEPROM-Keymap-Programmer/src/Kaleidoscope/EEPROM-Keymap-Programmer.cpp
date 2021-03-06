/* -*- mode: c++ -*-
 * Kaleidoscope-EEPROM-Keymap-Programmer -- On-the-fly reprogrammable keymap.
 * Copyright (C) 2017  Gergely Nagy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <Kaleidoscope-EEPROM-Keymap-Programmer.h>

namespace kaleidoscope {
uint16_t EEPROMKeymapProgrammer::update_position_;
EEPROMKeymapProgrammer::state_t EEPROMKeymapProgrammer::state_;
EEPROMKeymapProgrammer::mode_t EEPROMKeymapProgrammer::mode;
Key EEPROMKeymapProgrammer::new_key_;

EEPROMKeymapProgrammer::EEPROMKeymapProgrammer(void) {
}

void EEPROMKeymapProgrammer::begin(void) {
  Kaleidoscope.useEventHandlerHook(eventHandlerHook);
}

void EEPROMKeymapProgrammer::nextState(void) {
  switch (state_) {
  case INACTIVE:
    state_ = WAIT_FOR_KEY;
    break;
  case WAIT_FOR_KEY:
    if (mode == CODE)
      state_ = WAIT_FOR_CODE;
    else
      state_ = WAIT_FOR_SOURCE_KEY;
    break;
  case WAIT_FOR_CODE:
  case WAIT_FOR_SOURCE_KEY:
    ::EEPROMKeymap.updateKey(update_position_, new_key_);
    cancel();
    break;
  }
}

void EEPROMKeymapProgrammer::cancel(void) {
  update_position_ = 0;
  new_key_ = Key_NoKey;
  state_ = INACTIVE;
}

Key EEPROMKeymapProgrammer::eventHandlerHook(Key mapped_key, byte row, byte col, uint8_t key_state) {
  if (state_ == INACTIVE)
    return mapped_key;

  if (state_ == WAIT_FOR_KEY) {
    if (keyToggledOn(key_state)) {
      update_position_ = Layer.top() * ROWS * COLS + row * COLS + col;
    }
    if (keyToggledOff(key_state)) {
      if ((uint16_t)(Layer.top() * ROWS * COLS + row * COLS + col) == update_position_)
        nextState();
    }
    return Key_NoKey;
  }

  if (state_ == WAIT_FOR_SOURCE_KEY) {
    if (keyToggledOn(key_state)) {
      new_key_ = Layer.getKeyFromPROGMEM(Layer.top(), row, col);
    }
    if (keyToggledOff(key_state)) {
      if (new_key_ == Layer.getKeyFromPROGMEM(Layer.top(), row, col))
        nextState();
    }
    return Key_NoKey;
  }

  // WAIT_FOR_CODE state

  if (mapped_key < Key_1 || mapped_key > Key_0)
    return mapped_key;

  if (!keyToggledOn(key_state))
    return Key_NoKey;

  uint8_t n;
  if (mapped_key.keyCode == Key_0.keyCode)
    n = 0;
  else
    n = mapped_key.keyCode - Key_1.keyCode + 1;

  new_key_.raw = new_key_.raw * 10 + n;

  return Key_NoKey;
}

bool EEPROMKeymapProgrammer::focusHook(const char *command) {
  if (strcmp_P(command, PSTR("keymap.toggleProgrammer")) != 0)
    return false;

  if (state_ == INACTIVE)
    activate();
  else
    cancel();

  return true;
}

}

kaleidoscope::EEPROMKeymapProgrammer EEPROMKeymapProgrammer;
