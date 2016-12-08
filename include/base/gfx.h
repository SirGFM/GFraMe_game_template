/**
 * @file include/base/gfx.h
 *
 * Define the list of available textures and its respective spritesets.
 */
#ifndef __BASE_GFX_H__
#define __BASE_GFX_H__

#include <base/error.h>
#include <conf/gfx_list.h>

#include <GFraMe/gframe.h>
#include <GFraMe/gfmSpriteset.h>

struct stGfxCtx {
#define X(name, ...) \
    gfmSpriteset *name;
    SPRITESET_LIST
#undef X

#define X(name, ...) \
    int name;
    TEXTURE_LIST
#undef X
};
typedef struct stGfxCtx gfxCtx;

/** Global graphics context (declared on src/base/static.c) */
extern gfxCtx gfx;

/**
 * Load every texture and set the spritesets. Note that no manual clean up is
 * necessary because the framework handles everything by itself (as long as it's
 * correctly freed).
 */
err initGfx();

#endif /* __BASE_GFX_H__ */

