#ifndef UPDATABLE_HPP
#define UPDATABLE_HPP

#include "GameState.hpp"

class Updatable
{
private:
public:
	void Update(t_gamestate state);

	Updatable();
	~Updatable();
};

#endif