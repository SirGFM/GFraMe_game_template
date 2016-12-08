/**
 * @file include/base/setup.h
 *
 * Implement all initial setup
 */
#ifndef __SETUP_H__
#define __SETUP_H__

#include <base/error.h>

/**
 * Basic setup for the game.
 *
 * Load all basic configuration (from the command line and/or from a file on the
 * system). When the function returns (if successful), all sub-systems will be
 * ready for use:
 *  - The game window will be set up at the desired resolution (as defined on
 *    setup.h, where V_WIDTH and V_HEIGHT define the virtual window dimensions
 *    and the real window dimension is a multiple of that), audio will be ready
 *  - Audio will be ready to load and play songs at the requested quality
 *  - FPS will be configured and initialized
 *
 * Note that since the FPS is already configured, it's important to reset it
 * before starting the main loop. Otherwise, there may be some skipped frames on
 * startup.
 * Also, input must be manually set up later.
 *
 * @param  [ in]argc    Number of arguments received
 * @param  [ in]argv    List of arguments received
 * @return
 */
err setupGame(int argc, char *argv[]);

/**
 * Release all resources alloc'ed on 'setupGame'
 */
void cleanGame();

#endif /* __SETUP_H__ */

