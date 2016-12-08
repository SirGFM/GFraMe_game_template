/**
 * @file src/base/setup.h
 *
 * Implement all initial setup
 */
#include <base/cmdParse.h>
#include <base/game.h>
#include <base/setup.h>
#include <conf/config.h>
#include <conf/game.h>

#include <GFraMe/gfmError.h>
#include <GFraMe/gframe.h>

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
err setupGame(int argc, char *argv[]) {
    /* Temporary config struct */
    configCtx config;
    err erv;
    gfmRV rv;

    /* Alloc a new game context and set it's local directory (for logging and
     * save files) */
    rv = gfm_getNew(&game.pCtx);
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);
    rv = gfm_initStatic(game.pCtx, ORG, TITLE);
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);

    /* Parse the command line and initialize most sub-systems with the retrieved
     * values */
    erv = cmdParse(&config, argc, argv);
    ASSERT(erv == ERR_OK, erv);

    rv = gfm_setVideoBackend(game.pCtx, config.videoBackend);
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);
    if (config.fullscreen == 0) {
        rv = gfm_initGameWindow(game.pCtx, V_WIDTH, V_HEIGHT, config.wndWidth,
                config.wndHeight, 1/*allow resize*/, config.vsync);
    }
    else {
        rv = gfm_initGameFullScreen(game.pCtx, V_WIDTH, V_HEIGHT,
                config.fullscreenResolution, 1/*allow resize*/, config.vsync);
    }
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);

    rv = gfm_setBackground(game.pCtx, BG_COLOR);
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);

    rv = gfm_initAudio(game.pCtx, config.audioSettings);
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);

    rv = gfm_setFPS(game.pCtx, config.fpsQuality);
    if (rv == GFMRV_FPS_TOO_HIGH) {
        rv = gfm_setRawFPS(game.pCtx, config.fpsQuality);
    }
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);

    rv = gfm_setStateFrameRate(game.pCtx, config.fpsQuality,
            config.fpsQuality);
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);

    /* By default, render the FPS counter on debug mode */
    rv = gfm_showFPSCounter(game.pCtx);
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);
    rv = gfm_setFPSCounterPos(game.pCtx, 4/*x*/, 4/*y*/);
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);

#if defined(DEBUG)
    game.debugRunState = DBG_RUNNING;
#endif

    return ERR_OK;
}

/**
 * Release all resources alloc'ed on 'setupGame'
 */
void cleanGame() {
    if (game.pCtx) {
        gfm_free(&game.pCtx);
    }
}

