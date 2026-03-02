#include "../../include/core/main.hpp"

void resize_handling(t_gamestate state, Board *board, Menu *menu, Hud *hud)
{
	clear();

	refresh();

	if (LINES < 20 || COLS < 40)
	{
		state.mode = GameMode::MAIN_MENU;

		mvprintw(0, 0, "TERMINAL TOO SMALL! Please enlarge window.");
		refresh();
	}
	else
	{
		int new_board_y = (LINES / 2) - (BOARD_ROWS);
		int new_board_x = (COLS / 2) - (BOARD_COLS);
		
		mvwin(board->win, new_board_y, new_board_x);
		mvwin(menu->menu, new_board_y, new_board_x);
		
		mvwin(hud->hud, new_board_y, new_board_x - 15);
	}
}
