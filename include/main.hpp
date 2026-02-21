#ifndef MAIN_HPP
# define MAIN_HPP

# include <ncurses.h>
# include <chrono>
# include "Board.hpp"

# define BOARD_DIM 20
# define BOARD_ROWS BOARD_DIM
# define BOARD_COLS BOARD_DIM * 2

typedef struct s_gamestate {
	unsigned int		level;
	unsigned long long	time;
	unsigned int		score;
	unsigned int		lives;
	Player				
	list				enemies;

}				t_gamestate;

#endif
