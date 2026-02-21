#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity
{
private:
	Vector2 pos;
	
public:
	Player(/* args */);
	~Player();
};

#endif