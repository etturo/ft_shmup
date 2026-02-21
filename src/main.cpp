#include "../include/main.hpp"

int main()
{

	initscr();
	refresh();

	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	Board board = Board(yMax, xMax);


	endwin();

	return 0;
}