#include "../include/main.hpp"

t_gamestate	init_state()
{
	t_gamestate	state;
	
	state.level = 1;
	state.lives = 3;
	state.score = 0;
	return state;
}

int check_size()
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

int main(void)
{
	initscr();
	cbreak();
	noecho();
	refresh();
	curs_set(0);

	if (check_size() == false)
		return 1;
	Board *board = new Board();

	keypad(board->win, TRUE);
	nodelay(board->win, TRUE);
	
	t_gamestate	state = init_state();
	Player *player = new Player();
	state.entities.push_front(player);

	while (true)
	{
		state.pressed = wgetch(board->win);

		if (state.pressed == 'q')
			break;

		werase(board->win);
		box(board->win, 0, 0);

		for (Entity *entity : state.entities)
		{
			entity->update(state);
			entity->render(board->win);
		}

		wrefresh(board->win);

	}
	
	endwin();

	return (0);
}