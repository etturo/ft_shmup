#include "../include/world/Hud.hpp"

Hud::Hud(int height, int length)
{
	this->hud = newwin(height, length, (LINES / 2) - (BOARD_ROWS / 2), (COLS / 2) - (BOARD_COLS / 2) - 15);
}

Hud::~Hud()
{
	if (this->hud)
		delwin(this->hud);
}
