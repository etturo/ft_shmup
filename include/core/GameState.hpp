#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>
# include "GameMode.hpp"

class Entity;

typedef struct s_gamestate {
	int					level;
	long long			time = 0;
	long long			start_time;
	int					score;
	int					lives = 3;
	int					pressed;
	long long			delta_time = 0;
	long long			spawn_time = 0;
	long long			render_time = 0;
	bool				boss_active;
	GameMode			mode;
	std::list<Entity*>	entities;
	std::list<Entity*>	spawn_list;
}				t_gamestate;

#endif