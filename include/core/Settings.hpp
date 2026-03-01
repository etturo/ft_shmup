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

# define BOARD_ROWS 40
# define BOARD_COLS 50

# define HUD_ROWS 7
# define HUD_COLS 15

#define MENU_ROWS BOARD_ROWS / 2.5
#define MENU_COLS BOARD_ROWS

# define PLAYER_LIVES 3
# define SCORE_TO_LEVEL_UP 1000

# define GAME_TITLE R"(     /$$$$$$  /$$    /$$  /$$$$$$ 
    /$$__  $$| $$   | $$ /$$__  $$
   | $$  \ $$| $$   | $$| $$  \__/
   | $$  | $$|  $$ / $$/|  $$$$$$ 
   | $$  | $$ \  $$ $$/  \____  $$
   | $$  | $$  \  $$$/   /$$  \ $$
   |  $$$$$$/   \  $/   |  $$$$$$/
    \______/     \_/     \______/ 
                               )"

# define SPACESHIP ("-<O>-")
# define BULLET ("|")
# define ENEMY ("<\\v/>")
# define ENEMY_2 ("{0+0}")
# define ENEMY_BULLET ("o")
# define BOSS ("({*})~~(0^0)~~({*})")

# define MAX_HEIGHT (BOARD_ROWS - (BOARD_COLS / 4)) 

# define SECONDS(clock) (clock / 1000000000.0f)
# define TARGET_FRAME_TIME 1000000000LL / 60
# define GET_SPAWN_TIME(level) ((4 / level) + 0.2f)

#endif