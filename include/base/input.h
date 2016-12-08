/**
 * @file include/base/input.h
 *
 * Define the list of inputs and its handling functions
 */
#ifndef __BASE_INPUT_H__
#define __BASE_INPUT_H__

#include <base/error.h>
#include <conf/input_list.h>

#include <GFraMe/gfmInput.h>

/** Define a single button */
struct stButton {
    /** Button handle, internal to the framework */
    int handle;
    /** Number of times the button was consecutivelly pressed */
    int numPressed;
    /** Current state of the button */
    gfmInputState state;
    /** Ignore; Used to expand the struct to 32 bytes */
    int padding;
};
typedef struct stButton button;

/** Encapsulate every button */
struct stInputCtx {
#define X(name, ...) button name;
    X_BUTTON_LIST
#undef X
};
typedef struct stInputCtx inputCtx;

/** Global input (declared on src/base/static.c) */
extern inputCtx input;

/**
 * Handle every input that require an immediate action (i.e, those that are more
 * like flags, instead of being interpreted during the game loop).
 */
void handleInput();

#if defined(DEBUG)
/**
 * Handle the debug controls of the game's simulation. These allow the update
 * loop to be paused/resumed or even stepped.
 */
void handleDebugInput();
#endif

/** Retrieve the state of every button */
err updateInput();

/** Forcefully update every debug button */
err updateDebugInput();

/** Initialize every button with their default mapping */
err initInput();

/** Whether a given button is currently released */
#define IS_RELEASED(bt) \
    (input.bt.state & gfmInput_released)

/** Whether a given button is currently pressed */
#define IS_PRESSED(bt) \
    (input.bt.state & gfmInput_pressed)

/** Whether a state is just pressed */
#define IS_STATE_JUSTPRESSED(st) \
    ((st & gfmInput_justPressed) == gfmInput_justPressed)

/** Whether a state is just released */
#define IS_STATE_JUSTRELEASED(st) \
    ((st & gfmInput_justReleased) == gfmInput_justReleased)

/** Whether a given button was just pressed */
#define DID_JUST_PRESS(bt) \
    (IS_STATE_JUSTPRESSED(input.bt.state))

/** Whether a given button was just released */
#define DID_JUST_RELEASE(bt) \
    (IS_STATE_JUSTRELEASED(input.bt.state))


#endif /* __BASE_INPUT_H__ */

