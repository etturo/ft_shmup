#ifndef UPDATABLE_HPP
#define UPDATABLE_HPP

#include "GameState.hpp"

class Updatable
{
private:
public:
	void virtual update(t_gamestate state) = 0;

	Updatable();
	virtual ~Updatable();
};

#endif