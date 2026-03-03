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

# define MIN_LINES 15
# define MIN_COLS 40
# define MAX_COLS 80

# define BOARD_ROWS (LINES > MIN_LINES) ? LINES * 0.875 : LINES
# define BOARD_COLS (COLS > MIN_COLS) ? (COLS <= MAX_COLS ? COLS / 2.5 : MAX_COLS) : COLS

# define HUD_ROWS 7
# define HUD_COLS 15

# define MENU_ROWS (TITLE_ROWS + TITLE_OFFSET + 10)
# define MENU_COLS (TITLE_COLS + 5)

# define PLAYER_LIVES 3
# define SCORE_TO_LEVEL_UP 1000

# define GAME_TITLE R"(    /$$$$$$  /$$    /$$  /$$$$$$ 
   /$$__  $$| $$   | $$ /$$__  $$
  | $$  \ $$| $$   | $$| $$  \__/
  | $$  | $$|  $$ / $$/|  $$$$$$ 
  | $$  | $$ \  $$ $$/  \____  $$
  | $$  | $$  \  $$$/   /$$  \ $$
  |  $$$$$$/   \  $/   |  $$$$$$/
   \______/     \_/     \______/)"

# define TITLE_ROWS 8
# define TITLE_COLS 30
# define TITLE_OFFSET 2

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