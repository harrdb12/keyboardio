#pragma once

// This file contains aliases for Kaleidoscope's HID key definitions.
//
// These aliases are provided as a convenience for end users Our goal is to
// offer up macros that fit what users guess the macros might be called, while
// not polluting the main tables of aliases.
//
// The first group defined here provide short alternate names for a variety
// of keys.

#define Key_Space Key_Spacebar
#define Key_LBracket Key_LeftBracket
#define Key_LArrow Key_LeftArrow
#define Key_LCtrl  Key_LeftControl
#define Key_LShift Key_LeftShift
#define Key_LAlt Key_LeftAlt
#define Key_LGui Key_LeftGui
#define Key_RBracket  Key_RightBracket
#define Key_RArrow  Key_RightArrow
#define Key_RCtrl  Key_RightControl
#define Key_RShift  Key_RightShift
#define Key_RAlt  Key_RightAlt
#define Key_RGui  Key_RightGui
#define Key_Esc  Key_Escape

#define Key_LSquareBracket Key_LeftBracket
#define Key_RSquareBracket Key_RightBracket

// To match Key_UpArrow
#define Key_DnArrow Key_DownArrow


#define Key_LeftParen LSHIFT(Key_9)
#define Key_RightParen LSHIFT(Key_0)
#define Key_LeftCurlyBracket LSHIFT(Key_LeftBracket)
#define Key_RightCurlyBracket LSHIFT(Key_RightBracket)

#define Key_Pipe LSHIFT(Key_Backslash)

