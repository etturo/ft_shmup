#ifndef BOSS_HPP
#define BOSS_HPP

#include "Enemy.hpp"

class Boss : public Enemy
{
private:
	int dir = 0;
	int move = 0;
public:
	void update(t_gamestate &state) override;
	void render(WINDOW *win) override;

	void on_collision(Entity* other, t_gamestate &state) override;

	Boss();
	~Boss();
};

#endif