#include "Menu.hpp"

Menu::Menu(int height, int length)
{
	this->menu = newwin(height, length, (LINES / 2) - (height / 2), (COLS / 2) - (length / 2));
}

Menu::~Menu()
{
	if (this->menu)
		delwin(this->menu);
}
