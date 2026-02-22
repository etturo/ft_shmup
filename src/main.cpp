#include "../include/main.hpp"
#include <unistd.h>
#include <locale.h>

long long int get_current_time() {
	return std::chrono::steady_clock::now().time_since_epoch().count();
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
	setlocale(LC_ALL, "");
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
	state.entities.push_front(new Player());

	state.time = get_current_time();
	state.spawn_time = get_current_time();

	while (true)
	{
		state.pressed = wgetch(board->win);

		if (state.pressed == 'q')
			break;

		state.delta_time = get_current_time() - state.time;
		state.time = get_current_time();
		state.spawn_time += state.delta_time;

		werase(board->win);

		if (SECONDS(state.spawn_time) > SPAWN_RATE){
			state.spawn_list.push_front(new Enemy());
			state.spawn_time = 0;
		}
		
		// erase();
		// wprintw(stdscr, "time: %lld\n", state.spawn_time);
		// refresh();

		state.entities.splice(state.entities.begin(), state.spawn_list);
		state.spawn_list.clear();

		// erase();
		for (Entity *entity : state.entities)
		{
			entity->update(state);
			
			if (!entity->is_dead)
				entity->render(board->win);

			// wprintw(stdscr, "%p\n", entity);
		}
		// refresh();

		box(board->win, 0, 0);

		for (auto it1 = state.entities.begin(); it1 != state.entities.end(); ++it1) 
		{
			for (auto it2 = std::next(it1); it2 != state.entities.end(); ++it2) 
				{
  					Entity* a = *it1;
					Entity* b = *it2;

				if (a->is_dead || b->is_dead) continue;

				if (a->pos.x < b->pos.x + b->sprite_len &&
					a->pos.x + a->sprite_len > b->pos.x &&
					a->pos.y < b->pos.y + b->sprite_height &&
					a->pos.y + a->sprite_height > b->pos.y) 
				{
					a->on_collision(b, state);
					b->on_collision(a, state);
				}
			}
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
