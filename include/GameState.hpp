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
}				t_gamestate;

#endif