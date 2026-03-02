#include "../include/core/Init.hpp"

t_gamestate	init_state()
{
	t_gamestate	state;
	
	state.level = 1;
	state.lives = PLAYER_LIVES;
	state.score = 0;
	state.boss_active = false;
	state.mode = GameMode::MAIN_MENU;
	state.time = 0;
	state.delta_time = 0;
	state.spawn_time = 0;
	state.start_time = 0;
	state.render_time = 0;
	return state;
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

	return true;
}