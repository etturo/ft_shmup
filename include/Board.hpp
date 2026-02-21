#ifndef BOARD_HPP
# define BOARD_HPP

# include <ncurses.h>
# include <chrono>

# define BOARD_DIM 20
# define BOARD_ROWS BOARD_DIM
# define BOARD_COLS BOARD_DIM * 2

class Board
{
private:
	/* data */
public:
	Board(int yMax, int xMax);
	~Board();
};


#endif