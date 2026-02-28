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

# include "GameState.hpp"

# define BOARD_DIM 40
# define BOARD_ROWS BOARD_DIM
# define BOARD_COLS BOARD_DIM

#define SPAWN_RATE 5

# define SPACESHIP ("-<O>-")
# define BULLET ("|")
# define ENEMY ("<\\v/>")
# define ENEMY_2 ("{0+0}")
# define ENEMY_BULLET ("o")
# define BOSS ("({*})~~(0^0)~~({*})")

# define MAX_HEIGHT (BOARD_DIM - (BOARD_DIM / 4)) 
# define SECONDS(clock) (clock / 1000000000.0f)

#endif