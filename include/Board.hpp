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
	Board();
	~Board();
};


#endif