#include "../include/main.hpp"

t_gamestate	*init_state()
{
	t_gamestate	*state;
	
	state->level = 1;
	state->lives = 3;
	state->score = 0;
	return state;
}

int main(void)
{
	initscr();
	cbreak();
	noecho();
	refresh();
	
	t_gamestate	*state = init_state();
	while (1)
	{
		// input (key inputs)
		// update state (updates buffer & internal variables/state of the game in tempo reale)
		// render (print buffer)
	}
	int yMax, xMax;
	getmaxyx(stdscr, yMax, xMax);

	Board board = Board(yMax, xMax);
	
	endwin();

	return (0);
}