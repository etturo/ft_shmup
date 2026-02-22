#ifndef MAIN_HPP
# define MAIN_HPP

# include <ncurses.h>
# include <chrono>
# include <list>

# include "Board.hpp"
# include "Entity.hpp"
# include "Enemy.hpp"
# include "Player.hpp"
# include "Updatable.hpp"
# include "GameState.hpp"
# include "settings.hpp"
# include "Terrain.hpp"

t_gamestate	init_state();


#endif
