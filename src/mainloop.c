/**
 * @file src/mainloop.c
 */
#include <base/collision.h>
#include <base/error.h>
#include <base/game.h>
#include <base/input.h>
#include <base/mainloop.h>

#include <conf/state.h>

#include <GFraMe/gframe.h>
#include <GFraMe/gfmError.h>
#include <GFraMe/gfmQuadtree.h>

/** Run the main loop until the game is closed */
err mainloop() {
    err erv;
    gfmRV rv;

    /* TODO Init all global stuff */

    /* Set initial state */
    game.nextState = ST_DUMMY;

    while (gfm_didGetQuitFlag(game.pCtx) != GFMRV_TRUE) {
        /* Switch state */
        if (game.nextState != ST_NONE) {
            switch (game.nextState) {
                case ST_DUMMY: break;
                default: {}
            }
            ASSERT_TO(erv == ERR_OK, NOOP(), __ret);

            game.currentState = game.nextState;
            game.nextState = ST_NONE;
        }

        /* Wait for an event */
        rv = gfm_handleEvents(game.pCtx);
        ASSERT_TO(rv == GFMRV_OK, erv = ERR_GFMERR, __ret);

#if defined(DEBUG)
        erv = updateDebugInput();
        ASSERT_TO(erv == ERR_OK, NOOP(), __ret);
        handleDebugInput();
#endif

        while (DO_UPDATE()) {
            rv = gfm_fpsCounterUpdateBegin(game.pCtx);
            ASSERT_TO(rv == GFMRV_OK, erv = ERR_GFMERR, __ret);

            erv = updateInput();
            ASSERT_TO(erv == ERR_OK, NOOP(), __ret);
            handleInput();

            rv = gfm_getElapsedTime(&(game.elapsed), game.pCtx);
            ASSERT_TO(rv == GFMRV_OK, erv = ERR_GFMERR, __ret);

            /* Update the current state */
            switch (game.currentState) {
                case ST_DUMMY: break;
                default: {}
            }
            ASSERT_TO(erv == ERR_OK, NOOP(), __ret);

            rv = gfm_fpsCounterUpdateEnd(game.pCtx);
            ASSERT_TO(rv == GFMRV_OK, erv = ERR_GFMERR, __ret);

            DEBUG_STEP();
        }

        while (gfm_isDrawing(game.pCtx) == GFMRV_TRUE) {
            rv = gfm_drawBegin(game.pCtx);
            ASSERT_TO(rv == GFMRV_OK, erv = ERR_GFMERR, __ret);

            /* Render the current state */
            switch (game.currentState) {
                case ST_DUMMY: break;
                default: {}
            }
            ASSERT_TO(erv == ERR_OK, NOOP(), __ret);

            if (IS_QUADTREE_VISIBLE()) {
                rv = gfmQuadtree_drawBounds(collision.pStaticQt, game.pCtx, 0);
                ASSERT_TO(rv == GFMRV_QUADTREE_EMPTY
                        || rv == GFMRV_QUADTREE_NOT_INITIALIZED
                        || rv == GFMRV_OK, erv = ERR_GFMERR, __ret);
                rv = gfmQuadtree_drawBounds(collision.pQt, game.pCtx, 0);
                ASSERT_TO(rv == GFMRV_QUADTREE_EMPTY
                        || rv == GFMRV_QUADTREE_NOT_INITIALIZED
                        || rv == GFMRV_OK, erv = ERR_GFMERR, __ret);
            }

            rv = gfm_drawRenderInfo(game.pCtx, 0, 0/*x*/, 24/*y*/, 0);
            ASSERT_TO(rv == GFMRV_OK, erv = ERR_GFMERR, __ret);

            rv = gfm_drawEnd(game.pCtx);
            ASSERT_TO(rv == GFMRV_OK, erv = ERR_GFMERR, __ret);
        }
    }

    erv = ERR_OK;
__ret:
    /* TODO Free all global stuff */

    return erv;
}

