#pragma once
#include "Area.h"
#include "Location.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define D_SCREEN_WIDTH (1280)
#define D_SCREEN_HEIGHT (720)

#define D_GAME_SCREEN_LEFT (0)
#define D_GAME_SCREEN_RIGHT (1280)
#define D_GAME_SCREEN_UPPER (0)
#define D_GAME_SCREEN_FOOTER (720)

/******************************************
* óÒãìå^ÇÃêÈåæ
******************************************/
enum mode {
	TITLE,
	RANKING,
	MAIN,
};