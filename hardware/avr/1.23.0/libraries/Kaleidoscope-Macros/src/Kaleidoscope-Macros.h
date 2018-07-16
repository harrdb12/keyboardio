#pragma once

#include <Kaleidoscope.h>

#include "MacroKeyDefs.h"
#include "MacroSteps.h"

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState);

#if !defined(MAX_CONCURRENT_MACROS)
#define MAX_CONCURRENT_MACROS 8
#endif

struct MacroKeyEvent {
  byte key_code;
  byte key_id;
  byte key_state;
};

class Macros_ : public KaleidoscopePlugin {
 public:
  Macros_(void);

  void begin(void) final;

  static MacroKeyEvent active_macros[MAX_CONCURRENT_MACROS];
  static byte active_macro_count;
  static void addActiveMacroKey(byte key_code, byte key_id, byte key_state) {
    // If we've got too many active macros, give up:
    if (active_macro_count >= MAX_CONCURRENT_MACROS) {
      return;
    }
    active_macros[active_macro_count].key_code = key_code;
    active_macros[active_macro_count].key_id = key_id;
    active_macros[active_macro_count].key_state = key_state;
    ++active_macro_count;
  }
  static Key handleMacroEvent(Key mappedKey, byte row, byte col, uint8_t keyState);
  static void loopHook(bool post_clear);

  void play(const macro_t *macro_p);

  /* What follows below, is a bit of template magic that allows us to use
     Macros.type() with any number of arguments, without having to use a
     sentinel. See the comments on Kaleidoscope.use() for more details - this is
     the same trick.
   */
  inline const macro_t *type() {
    return MACRO_NONE;
  }
  const macro_t *type(const char *string);
  template <typename... Strings>
  const macro_t *type(const char *first, Strings&&... strings) {
    type(first);
    return type(strings...);
  }

  static byte row, col;

 private:
  Key lookupAsciiCode(uint8_t ascii_code);
};

extern Macros_ Macros;
