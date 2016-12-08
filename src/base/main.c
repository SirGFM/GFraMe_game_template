/**
 * @file src/main.c
 */
#include <base/collision.h>
#include <base/game.h>
#include <base/gfx.h>
#include <base/input.h>
#include <base/mainloop.h>
#include <base/setup.h>
#include <base/static.h>

/**
 * Entry point. Setup everything and handle cleaning up the game, when it exits
 *
 * @param  [ in]argc 
 * @param  [ in]argv 
 */
int main(int argc, char *argv[]) {
    err erv;

    zeroizeGlobalCtx();

    erv = setupGame(argc, argv);
    if (erv == ERR_FORCEEXIT) {
        erv = ERR_OK;
        goto __ret;
    }
    ASSERT_TO(erv == ERR_OK, erv = erv, __ret);

    erv = initGfx();
    ASSERT_TO(erv == ERR_OK, erv = erv, __ret);

    erv = initInput();
    ASSERT_TO(erv == ERR_OK, erv = erv, __ret);

    erv = setupCollision();
    ASSERT_TO(erv == ERR_OK, erv = erv, __ret);

    erv = mainloop();
__ret:
    cleanCollision();
    cleanGame();

    return erv;
}

