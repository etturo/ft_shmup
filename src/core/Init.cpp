#include "../include/core/Init.hpp"

t_gamestate	init_state()
{
	t_gamestate	state;
	
	state.level = 1;
	state.lives = PLAYER_LIVES;
	state.score = 0;
	state.boss_active = false;
	state.mode = GameMode::PLAYING;
	return state;
}

bool check_size()
{
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	if (yMax < BOARD_ROWS || xMax < BOARD_COLS) {
		endwin();
		printf("Error: Terminal is too small!\n");
		return false;
	}
	return true;
}

bool init_ncurses()
{
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	refresh();
	curs_set(0);
	start_color();
	use_default_colors();

	init_pair(1, COLOR_WHITE, -1);

	if (check_size() == false)
		return false;

	return true;
}