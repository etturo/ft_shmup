#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <chrono>
#include <ncurses.h>
#include <cstdlib>
#include <string.h>

# define BOARD_DIM 40
# define BOARD_ROWS BOARD_DIM
# define BOARD_COLS BOARD_DIM

#define SPAWN_RATE 2

# define SPACESHIP ("=<O>=")
# define BULLET ("|")
# define ENEMY ("<\\v/>")
# define ENEMY_BULLET ("o")

# define MAX_HEIGHT (BOARD_DIM - (BOARD_DIM / 4)) 
# define SECONDS(clock) (clock / 1000000000.0f)

#endif