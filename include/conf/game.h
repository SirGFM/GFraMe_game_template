/**
 * @file include/conf/game.h
 *
 * Define most constants that define the game
 */
#ifndef __CONF_GAME_H__
#define __CONF_GAME_H__

/** Width of the virtual window */
#define V_WIDTH     320
/** Height of the virtual window */
#define V_HEIGHT    240
/** Organization (directory created within %APPDATA% or ~/.local/share/ where
 * the the game's directory is located) */
#define ORG         "YOUR.ORGANIZATION"
/** Game's title (used both on the window's title bar and as the actual
 * sub-directory within ORG where logs and save data are stored) */
#define TITLE       "GAME_TITLE"
/** Initial background color (only for the virtual window) */
#define BG_COLOR    0xFF222034

#endif /* __CONF_GAME_H__ */

