/**
 * @file include/conf/config.h
 *
 * Describe the structure filled by cmdParse (and used during the game's
 * initialization).
 */
#ifndef __CONF_CONFIG_H__
#define __CONF_CONFIG_H__

#include <GFraMe/gframe.h>

/** Structure filled with all parsed configurations */
struct stConfigCtx {
    /** Whether vsync is enabled */
    int vsync;
    /** Whether the game should start in fullscreen */
    int fullscreen;
    /** Initial window width */
    int wndWidth;
    /** Initial window height */
    int wndHeight;
    /** Initial FPS (base FPS and update/draw rate) */
    int fpsQuality;
    /** Index of fullscreen resolution (if on fullscreen mode) */
    int fullscreenResolution;
    /** Video backend */
    gfmVideoBackend videoBackend;
    /** Audio quality */
    gfmAudioQuality audioSettings;
};
typedef struct stConfigCtx configCtx;

/** Initialize the configuration struct with the default values */
#define CONFIG_INIT(c) \
  do { \
    (c).vsync = 0;\
    (c).fullscreenResolution = 0; \
    (c).fullscreen = 0;\
    (c).wndWidth = 640;\
    (c).wndHeight = 480;\
    (c).fpsQuality = 60;\
    (c).videoBackend = GFM_VIDEO_SDL2;\
    (c).audioSettings = gfmAudio_defQuality;\
  } while (0)

#endif /* __CONF_CONFIG_H__ */

