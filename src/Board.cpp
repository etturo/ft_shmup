#include "../include/Board.hpp"

Board::Board()
{
	this->win = newwin(BOARD_ROWS, BOARD_COLS, (LINES / 2) - (BOARD_ROWS / 2), (COLS / 2) - (BOARD_COLS / 2));
	//wrefresh(this->win);
};

Board::~Board() {
	if (this->win)
		delwin(this->win);
}