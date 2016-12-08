/**
 * @file include/base/mainloop.h
 *
 * Define the signature of the main loop. Note that the function is actually
 * implemented on src/mainloop.c (instead of src/base/mainloop.c), since it may
 * be modified for each specific game.
 */
#ifndef __BASE_MAINLOOP_H__
#define __BASE_MAINLOOP_H__

#include <base/error.h>

/** Run the main loop until the game is closed */
err mainloop();

#endif /* __BASE_MAINLOOP_H__ */

