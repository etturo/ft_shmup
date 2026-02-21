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
	Board(int yMax, int xMax)
	{
		getmaxyx(stdscr, yMax, xMax);


		WINDOW *board_win = newwin(BOARD_ROWS, BOARD_COLS, (yMax / 2) - (BOARD_ROWS / 2), (xMax / 2) - (BOARD_COLS / 2));
		box(board_win, 0, 0);
		wrefresh(board_win);

		getch();
	};


	~Board(){};
};


#endif