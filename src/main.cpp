#include "../include/main.hpp"

t_gamestate	init_state()
{
	t_gamestate	state;
	
	state.level = 1;
	state.lives = 3;
	state.score = 0;
	return state;
}

int main(void)
{
	initscr();
	cbreak();
	noecho();
	refresh();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);

	// int yMax, xMax;
	// getmaxyx(stdscr, yMax, xMax);

	// Board board = Board(yMax, xMax);
	t_gamestate	state = init_state();

	Player player = Player();
	state.entities.push_front(&player);
	while (true)
	{
		state.pressed = wgetch(/* board.win */stdscr);
		werase(/* board.win */stdscr);
		// box(/* board.win */, 0, 0);
		for (Entity *entity : state.entities)
		{
			entity->update(state);
			entity->render(/* board.win */stdscr);
		}
		wrefresh(/* board.win */stdscr);
	}
	
	endwin();

	return (0);
}