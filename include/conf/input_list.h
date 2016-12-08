/**
 * @file include/conf/input_list.h
 *
 * List of available buttons and their default keys.
 *
 * To make the most of this header, a 'X' macro must be defined, which will do
 * something with each parameter. The first will is the name of the virtual
 * button (TBD whether an enum within an array or a member within a struct), the
 * second is the default keyboard mapping and the last (if available) is the
 * default gamepad mapping.
 */
#ifndef __INPUT_LIST_H__
#define __INPUT_LIST_H__

/** Create a list of buttons and their default mapping. */
#define X_RELEASE_BUTTON_LIST \
  X(pause \
      , gfmKey_esc \
      , gfmController_start) \
  X(fullscreen \
      , gfmKey_f12)
//e.g. | var |     key     | gamepad button (port 1)
//    X(left , gfmKey_left , gfmController_laxis_left)

/** Create a list of debug buttons */
#if defined(DEBUG)
#  define X_DEBUG_BUTTON_LIST \
     X(qt         , gfmKey_f11) \
     X(gif        , gfmKey_f10) \
     X(dbgStep    , gfmKey_f6) \
     X(dbgPause   , gfmKey_f5)
#else
#  define X_DEBUG_BUTTON_LIST
#endif

/** Concatenate both lists */
#define X_BUTTON_LIST \
  X_RELEASE_BUTTON_LIST \
  X_DEBUG_BUTTON_LIST

#endif /* __INPUT_LIST_H__ */

