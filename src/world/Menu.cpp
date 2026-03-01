#include "../../include/world/Menu.hpp"
#include "Menu.hpp"

Menu::Menu(int height, int length)
{
	this->menu = newwin(height, length, (LINES / 2) - (BOARD_ROWS / 4), (COLS / 2) - (BOARD_COLS / 2.5));
}

Menu::~Menu()
{
	if (this->menu)
		delwin(this->menu);
}
