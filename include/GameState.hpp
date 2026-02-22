#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>

class Entity;

typedef struct s_gamestate {
	int					level;
	long long			time;
	int					score;
	int					lives;
	int					pressed;
	long long			delta_time;
	std::list<Entity*>	entities;
	std::list<Entity*>	spawn_list;
}				t_gamestate;

#endif