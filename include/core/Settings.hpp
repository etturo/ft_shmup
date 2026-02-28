#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <chrono>
#include <ncurses.h>
#include <cstdlib>
#include <string.h>
#include <string>
#include <deque>
#include <list>
#include <unistd.h>
#include <locale.h>

# define BOARD_DIM 40
# define BOARD_ROWS BOARD_DIM
# define BOARD_COLS BOARD_DIM

# define PLAYER_LIVES 3
# define SCORE_TO_LEVEL_UP 1000

# define HUD_ROWS 7
# define HUD_COLS 15

# define SPACESHIP ("-<O>-")
# define BULLET ("|")
# define ENEMY ("<\\v/>")
# define ENEMY_2 ("{0+0}")
# define ENEMY_BULLET ("o")
# define BOSS ("({*})~~(0^0)~~({*})")

# define MAX_HEIGHT (BOARD_DIM - (BOARD_DIM / 4)) 
# define SECONDS(clock) (clock / 1000000000.0f)
# define GET_SPAWN_TIME(level) ((4 / level) + 0.3f)

#endif