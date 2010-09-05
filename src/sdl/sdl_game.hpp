/* ========================================================================== */
/*                          STC - SIMPLE TETRIS CLONE                         */
/* -------------------------------------------------------------------------- */
/*   Constants and definitions for simple pure SDL implementation.            */
/*                                                                            */
/*   Copyright (c) 2010 Laurens Rodriguez Oscanoa.                            */
/*   This code is licensed under the MIT license:                             */
/*   http://www.opensource.org/licenses/mit-license.php                       */
/* -------------------------------------------------------------------------- */

#include "../game.hpp"

#ifdef STC_USE_SIMPLE_SDL

#include <SDL.h>

/* 
 * UI layout (quantities are expressed in pixels)
 */

/* Screen size */
#define SCREEN_WIDTH    (480)
#define SCREEN_HEIGHT   (272)

/* Size of square tile */
#define TILE_SIZE       (12)

/* Board up-left corner coordinates */
#define BOARD_X         (180)
#define BOARD_Y         (4)

/* Preview tetromino position */
#define PREVIEW_X       (112)
#define PREVIEW_Y       (210)

/* Score position and length on screen */
#define SCORE_X         (72)
#define SCORE_Y         (52)
#define SCORE_LENGTH    (10)

/* Lines position and length on screen */
#define LINES_X         (108)
#define LINES_Y         (34)
#define LINES_LENGTH    (5)

/* Level position and length on screen */
#define LEVEL_X         (108)
#define LEVEL_Y         (16)
#define LEVEL_LENGTH    (5)

/* Tetromino subtotals position */
#define TETROMINO_X     (425)
#define TETROMINO_L_Y   (53)
#define TETROMINO_I_Y   (77)
#define TETROMINO_T_Y   (101)
#define TETROMINO_S_Y   (125)
#define TETROMINO_Z_Y   (149)
#define TETROMINO_O_Y   (173)
#define TETROMINO_J_Y   (197)
#define TETROMINO_LENGTH    (5)

/* Tetromino total position */
#define PIECES_X        (418)
#define PIECES_Y        (221)
#define PIECES_LENGTH   (6)

/* Size of number */
#define NUMBER_WIDTH    (7)
#define NUMBER_HEIGHT   (9)

/* 
 * Image files
 */ 
#define BMP_TILE_BLOCKS     "sdl/blocks.png"
#define BMP_BACKGROUND      "sdl/back.png"
#define BMP_NUMBERS         "sdl/numbers.png"

/* Use 32 bits per pixel */
#define SCREEN_BIT_DEPTH        (32)

/* Use video hardware and double buffering */
#define SCREEN_VIDEO_MODE       (SDL_HWSURFACE | SDL_DOUBLEBUF)

/* Delayed autoshift initial delay */
#define DAS_DELAY_TIMER     (200)

/* Delayed autoshift timer for left and right moves */
#define DAS_MOVE_TIMER      (40)

/* Here we define the platform dependent implementation */
class StcPlatformSdl : public StcPlatform {
  public:
    virtual int init();
    virtual void end();

    /* Read input device and notify game */
    virtual void readInput(StcGame *gameInstance);

    /* Render the state of the game */
    virtual void renderGame(StcGame *gameInstance);

    /* Return the current system time in milliseconds */
    virtual long getSystemTime();

  private:
    SDL_Surface* screen;
    SDL_Surface* bmpTiles;
    SDL_Surface* bmpBack;
    SDL_Surface* bmpNumbers;

    /* For delayed autoshift: http://tetris.wikia.com/wiki/DAS */
    int delayLeft;
    int delayRight;
    int delayDown;
    int lastTime;

    void drawTile(StcGame *game, int x, int y, int tile, int shadow = 0);
    void drawNumber(StcGame *game, int x, int y, long number, int length, int color);
};

#endif /* STC_USE_SIMPLE_SDL */