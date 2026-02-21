#include "../include/main.hpp"
#include <unistd.h>

long long int get_current_time() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::steady_clock::now().time_since_epoch()
	).count();
}

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

	state.time = get_current_time();

	while (true)
	{

		state.pressed = wgetch(board->win);

		flushinp();

		if (state.pressed == 'q')
			break;

		state.delta_time = get_current_time() - state.time;
		state.time = get_current_time();

		werase(board->win);
		box(board->win, 0, 0);

		for (Entity *entity : state.entities)
		{
			entity->update(state);
			
			if (!entity->is_dead)
				entity->render(board->win);
		}

		state.entities.remove_if([](Entity *entity) 
		{
			if (entity->is_dead)
			{
				delete entity;
				return true;
			}
			return false;
		});

		wrefresh(board->win);
	}
	
	endwin();
	return (0);
}
