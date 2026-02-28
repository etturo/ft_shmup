#include "../include/world/Board.hpp"

Board::Board(int height, int length)
{
	this->win = newwin(height, length, (LINES / 2) - (height / 2), (COLS / 2) - (length / 2));
};

Board::~Board() {
	if (this->win)
		delwin(this->win);
}