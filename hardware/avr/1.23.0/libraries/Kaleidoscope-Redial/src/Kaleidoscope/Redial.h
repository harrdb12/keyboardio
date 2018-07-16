/* -*- mode: c++ -*-
 * Kaleidoscope-Redial -- Redial support for Kaleidoscope
 * Copyright (C) 2018  Gergely Nagy
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

#pragma once

#include <Kaleidoscope.h>

namespace kaleidoscope {

class Redial : public KaleidoscopePlugin {
 public:
  Redial(void) {};

  void begin(void) final;

  static Key key;

  static bool shouldRemember(Key mappedKey);

 private:
  static Key key_to_redial_;

  static Key eventHandlerHook_(Key mapped_key, byte row, byte col, uint8_t key_state);
};

}

extern kaleidoscope::Redial Redial;
