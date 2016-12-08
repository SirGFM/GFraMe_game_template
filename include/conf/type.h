/**
 * @file include/conf/type.h
 *
 * Define all in-game types.
 */
#ifndef __CONF_TYPE_H__
#define __CONF_TYPE_H__

#include <GFraMe/gfmTypes.h>

/** Mask that return the proper 16 bit type */
#define T_MASK 0x0000ffff
/** Number of bits per type */
#define T_BITS 16
/**
 * How many bits there are for any given "base type". Different types that share
 * the same base one will be rendered within the quadtree with the same color.
 */
#define T_BASE_NBITS 5

/** Retrieve an object's type (mask out all non-type bits) */
#define TYPE(type) \
    (type & T_MASK)

enum enType {
/**
 * Example extracted from JJAT2 (WIP)
 *
 * NOTE: T_FLOOR was kept outside because the enum can't be empty...
 */
      T_FLOOR     = gfmType_reserved_5  /* purple */
#if 0
    , T_PLAYER    = gfmType_reserved_7  /* light red */
    , T_FX        = gfmType_reserved_10 /* dirty yellow/green */

    , T_SWORDY     = (1 << T_BASE_NBITS) | T_PLAYER
    , T_GUNNY      = (2 << T_BASE_NBITS) | T_PLAYER
    , T_ATK_SWORD  = (3 << T_BASE_NBITS) | T_PLAYER
    , T_SWORD_FX   = (3 << T_BASE_NBITS) | T_FX
    , T_TEL_BULLET = (4 << T_BASE_NBITS) | T_PLAYER
#endif
};
typedef enum enType type;

#endif /* __CONF_TYPE_H__ */

