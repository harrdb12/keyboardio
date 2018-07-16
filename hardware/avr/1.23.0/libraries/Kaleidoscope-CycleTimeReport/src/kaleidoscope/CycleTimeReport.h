/* -*- mode: c++ -*-
 * Kaleidoscope-CycleTimeReport -- Scan cycle time reporting
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

#pragma once

#include <Kaleidoscope.h>

namespace kaleidoscope {
class CycleTimeReport : public KaleidoscopePlugin {
 public:
  CycleTimeReport() {}

  void begin(void) final;

  static uint32_t average_loop_time;
 private:
  static uint32_t next_report_time_;
  static uint32_t loop_start_time_;

  static void loopHook(bool post_clear);
};
}

void cycleTimeReport(void);

extern kaleidoscope::CycleTimeReport CycleTimeReport;
