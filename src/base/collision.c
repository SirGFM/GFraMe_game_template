/**
 * @file src/base/collision.c
 *
 * Declare all setup functions for the collision
 */
#include <base/collision.h>
#include <base/error.h>

#include <GFraMe/gfmQuadtree.h>

/** Setup the collision context */
err setupCollision() {
    gfmRV rv;
    
    rv = gfmQuadtree_getNew(&collision.pQt);
    if (rv != GFMRV_OK) {
        return ERR_GFMERR;
    }
    rv = gfmQuadtree_getNew(&collision.pStaticQt);
    if (rv != GFMRV_OK) {
        return ERR_GFMERR;
    }

    return ERR_OK;
}

/** Release all memory used by the collision context */
void cleanCollision() {
    if (collision.pQt != 0) {
        gfmQuadtree_free(&collision.pQt);
    }
    if (collision.pStaticQt != 0) {
        gfmQuadtree_free(&collision.pStaticQt);
    }
}

