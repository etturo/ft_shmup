#ifndef MAIN_HPP
# define MAIN_HPP

# include <ncurses.h>
# include <chrono>
# include <list>

# include "Board.hpp"
# include "Entity.hpp"
# include "Enemy.hpp"
# include "Player.hpp"
# include "Updatable.hpp"
# include "GameState.hpp"

# define BOARD_DIM 20
# define BOARD_ROWS BOARD_DIM
# define BOARD_COLS BOARD_DIM * 2

t_gamestate	init_state();


#endif
