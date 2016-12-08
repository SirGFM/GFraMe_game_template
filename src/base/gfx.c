/**
 * @file src/base/gfx.c
 *
 * Define the list of available textures and its respective spritesets.
 */
#include <base/error.h>
#include <base/game.h>
#include <base/gfx.h>

#include <GFraMe/gframe.h>
#include <GFraMe/gfmSpriteset.h>

/**
 * Load every texture and set the spritesets. Note that no manual clean up is
 * necessary because the framework handles everything by itself (as long as it's
 * correctly freed).
 */
err initGfx() {
    gfmRV rv;

    /* Load every texture */
#define X(name, texture, colorkey) \
    rv = gfm_loadTextureStatic(&gfx.name, game.pCtx, texture, colorkey); \
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);
    TEXTURE_LIST
#undef X

    /* Initialize every spriteset */
#define X(name, width, height, texture) \
    rv = gfm_createSpritesetCached(&gfx.name, game.pCtx, gfx.texture, width \
            , height); \
    ASSERT(rv == GFMRV_OK, ERR_GFMERR);
    SPRITESET_LIST
#undef X

    return ERR_OK;
}

