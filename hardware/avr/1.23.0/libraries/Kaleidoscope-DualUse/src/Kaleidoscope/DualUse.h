/* -*- mode: c++ -*-
 * Kaleidoscope-DualUse -- Dual use keys for Kaleidoscope
 * Copyright (C) 2016, 2017, 2018  Gergely Nagy
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

#include <Kaleidoscope-Qukeys.h>

namespace kaleidoscope {
class DualUse : public KaleidoscopePlugin {
 public:
  static class {
   public:
    uint16_t operator=(const uint16_t& other) {
      ::Qukeys.setTimeout(other);
      return other;
    }
    uint16_t operator=(const uint16_t&& other) {
      ::Qukeys.setTimeout(other);
      return other;
    }
  } time_out;

  DualUse(void) {};

  void begin(void) final { ::Qukeys.begin(); };
};
}

extern kaleidoscope::DualUse DualUse
__attribute__((deprecated("Consider using Qukeys directly, around which DualUse is a wrapper now.")));
