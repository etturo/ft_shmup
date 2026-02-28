#ifndef BOARD_HPP
# define BOARD_HPP

# include <ncurses.h>
# include <chrono>
# include "Settings.hpp"

class Board
{
private:
public:
	WINDOW *win;
	Board();
	~Board();
};


#endif