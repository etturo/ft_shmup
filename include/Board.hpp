#ifndef BOARD_HPP
# define BOARD_HPP

# include <ncurses.h>
# include <chrono>
# include "settings.hpp"

class Board
{
private:
public:
	WINDOW *win;
	Board(int yMax, int xMax);
	~Board();
};


#endif