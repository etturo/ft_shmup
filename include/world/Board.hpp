#ifndef BOARD_HPP
# define BOARD_HPP

# include "Settings.hpp"

class Board
{
private:
public:
	WINDOW *win;
	Board(int height, int length);
	~Board();
};


#endif