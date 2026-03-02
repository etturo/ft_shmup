#include "../include/core/main.hpp"

int main(void)
{
	if (init_ncurses() == false)
		return 1;

	Board *board = new Board(BOARD_ROWS, BOARD_COLS);
	Hud *hud = new Hud(HUD_ROWS, HUD_COLS);
	Menu *menu = new Menu(MENU_ROWS, MENU_COLS);

	Terrain background(BOARD_COLS, BOARD_ROWS);

	keypad(board->win, TRUE);
	nodelay(board->win, TRUE);
	
	t_gamestate	state = init_state();

	Player *player = new Player();
	state.entities.push_front(player);

	state.time = get_current_time();
	state.spawn_time = state.time;
	state.start_time = state.time;

	bool is_running = true;

	while (is_running && state.pressed != 'q')
	{
		// Taking the key input
		state.pressed = wgetch(board->win);

		if (state.pressed == KEY_RESIZE)
			resize_handling(state, board, menu, hud);

		// Calculating the current delta time
		state.delta_time = get_current_time() - state.time;
		state.time = get_current_time();

		//Updating independently of the state of the game the background
		background.update(state);

		state.render_time += state.delta_time;

		switch (state.mode)
		{
			/*===============================================================*/
			case GameMode::MAIN_MENU:
			{
				if (state.pressed == '\n')
				{
					state.mode = GameMode::PLAYING;\
					break;
				}

				if (state.render_time >= TARGET_FRAME_TIME)
				{
					werase(board->win);
					werase(menu->menu);

					// Render the background only based on target frame rate
					background.render(board->win);

					box(board->win, 0, 0);

					wprintw(menu->menu, "\n\n");
					wprintw(menu->menu, GAME_TITLE);
					wprintw(menu->menu, "\n  ===================================\n");
					wprintw(menu->menu, "\n   PRESS ENTER TO START A NEW GAME");
					box(menu->menu, 0, 0);

					// wrefresh(board->win);
					// wrefresh(menu->menu);

					wnoutrefresh(board->win);
					wnoutrefresh(menu->menu);
					doupdate();

					state.render_time -= TARGET_FRAME_TIME;
				}
				break;
			}
			/*===============================================================*/
			case GameMode::PLAYING:
			{
				// Checking if the player isn't dead or the player press 'q' to quit
				if (player->is_dead || state.pressed == 'q')
				{
					for (Entity *entity : state.entities)
						delete(entity);
					for (Entity *entity : state.spawn_list)
						delete(entity);
					state.mode = GameMode::GAME_OVER;
					break;
				}

				// Setting up the spawn time
				state.spawn_time += state.delta_time;

				// Checking the delta time and choosing if spawn an Enemy or not
				if ((SECONDS(state.spawn_time) > GET_SPAWN_TIME(state.level)) \
						&& state.level != 3){
					state.spawn_list.push_front(new Enemy());
					state.spawn_time = 0;
				}
				// If the level is 3 then summon a BOSS
				if (state.level == 3 && state.boss_active == false)
				{
					state.boss_active = true;
					state.spawn_list.push_front(new Boss());
				}

				// Insert the entities in the spwan 'waiting' list to the effective entitiy list
				state.entities.splice(state.entities.begin(), state.spawn_list);
				state.spawn_list.clear();

				// Loop to update every enetity
				for (Entity *entity : state.entities)
					entity->update(state);

				// Double iterator to check collision
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

				// Updating the lives of the player
				state.lives = player->get_hp();

				// Removing all dead entities
				state.entities.remove_if([](Entity *entity) 
				{
					if (entity->is_dead)
					{
						delete entity;
						return true;
					}
					return false;
				});

				// RENDER all the stuff within the right frametime
				if (state.render_time >= TARGET_FRAME_TIME)
				{
					// Cleaning the screen, ready to render the new state
					werase(board->win);
					werase(hud->hud);

					// Upadating the background every frame so is continuous to the other game states
					background.update(state);
					// Calling the render of the background
					background.render(board->win);

					// Rendering every entity if is not dead
					for (Entity *entity : state.entities)
						if (!entity->is_dead)
							entity->render(board->win);

					wrefresh(board->win);
					wrefresh(hud->hud);

					state.render_time -= TARGET_FRAME_TIME;
				}

				// Drawing the box containing the game
				box(board->win, 0, 0);

				long long elapsed = static_cast<long long>((state.time - state.start_time) / 1000000000LL);
				state.level = state.score / 1000 + 1;
				wprintw(hud->hud, "\n LIVES: %d\n SCORE: %d\n LEVEL: %d\n TIME: %02lld:%02lld", state.lives, state.score, state.level, elapsed / 60, elapsed % 60);

				box(hud->hud, 0, 0);

				break;
			}
			/*===============================================================*/
			case GameMode::PAUSED:
			{
				break;
			}
			/*===============================================================*/
			case GameMode::GAME_OVER:
			{
				printw("GAME OVER!\n");
				break;
			}
		}
	}

	delete(board);
	delete(hud);
	delete(menu);

	printw("\nPRESS ENTER TO EXIT...\n");
	while (getch() != '\n') {}
	endwin();
	return (0);
}
