/**
 * @file include/base/collision.h
 */
#ifndef __BASE_COLLISION_H__
#define __BASE_COLLISION_H__

#include <base/error.h>

#include <GFraMe/gfmQuadtree.h>

struct stCollisionCtx {
    /** Quadtree's root */
    gfmQuadtreeRoot *pQt;
    /** Static quadtree's root */
    gfmQuadtreeRoot *pStaticQt;
    /** Whether pending collisions (for the current object) should be skipped */
    int skip;
#if defined(DEBUG)
    /** Quadtree's visibility */
    int visibility;
#endif
};
typedef struct stCollisionCtx collisionCtx;

/** Collision context. Declared on src/base/static.c. */
extern collisionCtx collision;

/** Setup the collision context */
err setupCollision();

/** Release all memory used by the collision context */
void cleanCollision();

/**
 * Continue handling collision.
 * 
 * Different from the other functions on this module, this one is declared on
 * src/collision.c (instead of src/base/collision.c). This decision was made
 * because this function shall be modified for each game.
 *
 * @param  [ in]pQt The current quadtree
 */
err doCollide(gfmQuadtreeRoot *pQt);

/** Skip any pending collision for the current object */
#define skipCollision() do { collision.skip = 1; } while (0)

/** Checks whether the quadtree should be rendered */
#if defined(DEBUG)
#  define IS_QUADTREE_VISIBLE() (collision.visibility)
#else
#  define IS_QUADTREE_VISIBLE() (0)
#endif

#endif /* __BASE_COLLISION_H__ */

