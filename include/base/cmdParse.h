/**
 * @file include/base/cmdParse.h
 *
 * Module to parse command line options.
 *
 * Supported options:
 *  --backend | -b: Set the video backend {OpenGL, SDL, Software}
 *  --pixel-resolution | -x: Set the initial upcaling factor
 *  --FPS | -F: Set the game's initial (and maximum) FPS
 *  --resolution | -r: Set which resolution is to be used on fullscreen mode
 *  --audio | -a: *TODO* Set the audio quality
 *  --vsync | -v: Enable VSync
 *  --fullscreen | -f: Init game in fullscreen mode
 *  --list | -l: List all available resolution
 *  --save | -s: *TODO* Save the current configuration
 *  --help | -h: Print usage
 */
#ifndef __CMD_PARSE_H__
#define __CMD_PARSE_H__

#include <base/error.h>
#include <conf/config.h>

/**
 * Parse every command
 *
 * @param  [out]pConfig Struct filled with all initial configurations
 * @param  [ in]argc    Number of arguments received
 * @param  [ in]argv    List of arguments received
 * @return           
 */
err cmdParse(configCtx *pConfig, int argc, char *argv[]);

#endif /* __CMD_PARSE_H__ */

