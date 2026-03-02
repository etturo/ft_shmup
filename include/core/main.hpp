#ifndef MAIN_HPP
# define MAIN_HPP

# include "Board.hpp"
# include "Entity.hpp"
# include "Enemy.hpp"
# include "Player.hpp"
# include "Updatable.hpp"
# include "GameState.hpp"
# include "Settings.hpp"
# include "Terrain.hpp"
# include "Boss.hpp"
# include "Utils.hpp"
# include "Init.hpp"
# include "Hud.hpp"
# include "GameMode.hpp"
# include "Menu.hpp"

t_gamestate	init_state();

void resize_handling(t_gamestate state, Board *board, Menu *menu, Hud *hud);

int main(void);

#endif
