#ifndef BULLET_H
# define BULLET_H

#include "Entity.hpp"

class Bullet : public Entity
{
private:
public:
	void update(t_gamestate state) override;
	void render(WINDOW *win) override;

	Bullet(Vector2 player_pos);
	~Bullet();
};


#endif