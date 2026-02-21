#include "../include/Board.hpp"

Board::Board()
{
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	this->win = newwin(BOARD_ROWS, BOARD_COLS, (yMax / 2) - (BOARD_ROWS / 2), (xMax / 2) - (BOARD_COLS / 2));
	wrefresh(this->win);
};

Board::~Board() {
	if (this->win)
		delwin(this->win);
}