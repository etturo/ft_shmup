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
	start_color();
	use_default_colors();

	init_pair(1, COLOR_WHITE, -1);

	if (check_size() == false)
		return 1;
	Board *board = new Board();
	WINDOW *hud = newwin(10, 15, (LINES / 2) - (BOARD_ROWS / 2), (COLS / 2) - (BOARD_COLS / 2) - 15);

	Terrain background(BOARD_COLS, BOARD_ROWS);

	keypad(board->win, TRUE);
	nodelay(board->win, TRUE);
	
	t_gamestate	state = init_state();

	Player *player = new Player();
	state.entities.push_front(player);

	state.time = get_current_time();
	state.spawn_time = get_current_time();
	state.start_time = get_current_time();

	while (true)
	{
		if (player->is_dead)
		{
			for (Entity *entity : state.entities)
				delete(entity);
			for (Entity *entity : state.spawn_list)
				delete(entity);
			printw("GAME OVER!\n");
			break;
		}

		state.pressed = wgetch(board->win);

		if (state.pressed == 'q')
			break;

		state.delta_time = get_current_time() - state.time;
		state.time = get_current_time();
		state.spawn_time += state.delta_time;

		werase(board->win);
		werase(hud);

		background.update(state);
		background.render(board->win);

		if ((SECONDS(state.spawn_time) > (SPAWN_RATE / ((state.score / 1000) + 1) + 1)) && state.level != 1){
			state.spawn_list.push_front(new Enemy());
			state.spawn_time = 0;
		}
		if (state.level == 1 && state.boss_active == false)
		{
			state.boss_active = true;
			state.spawn_list.push_front(new Boss());
		}

		state.entities.splice(state.entities.begin(), state.spawn_list);
		state.spawn_list.clear();

		for (Entity *entity : state.entities)
		{
			entity->update(state);

			if (!entity->is_dead)
				entity->render(board->win);
		}

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

		state.lives = player->get_hp();

		state.entities.remove_if([](Entity *entity) 
		{
			if (entity->is_dead)
			{
				delete entity;
				return true;
			}
			return false;
		});

		box(board->win, 0, 0);

		long long elapsed = static_cast<long long>((state.time - state.start_time) / 1000000000LL);
		state.level = state.score / 1000 + 1;
		wprintw(hud, "\n LIVES: %d\n SCORE: %d\n LEVEL: %d\n TIME: %02lld:%02lld", state.lives, state.score, state.level, elapsed / 60, elapsed % 60);

		box(hud, 0, 0);

		wrefresh(board->win);
		wrefresh(hud);
	}

	delete(board);

	printw("PRESS RETURN TO EXIT...\n");
	while (getch() != '\n') {}
	endwin();
	return (0);
}
