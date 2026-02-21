#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <list>

#include "Entity.hpp"

typedef struct s_gamestate {
	unsigned int		level;
	unsigned long long	time;
	unsigned int		score;
	unsigned int		lives;
	std::list<Entity>	entities;
}				t_gamestate;

#endif